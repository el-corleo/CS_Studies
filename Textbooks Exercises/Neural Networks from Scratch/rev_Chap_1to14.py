import numpy as np
import nnfs
from nnfs.datasets import spiral_data

nnfs.init()

# LAYER
class Layer_Dense:
    
    def __init__(self, n_inputs, n_neurons,
                 weight_reg_L1=0, weight_reg_L2=0,
                 bias_reg_L1=0, bias_reg_L2=0):
        # init wieghts and biases
        self.weights = 0.01 * np.random.randn(n_inputs, n_neurons)
        self.biases = np.zeros((1, n_neurons))
        # init regularization strength
        self.weight_reg_L1 = weight_reg_L1
        self.weight_reg_L2 = weight_reg_L2
        self.bias_reg_L1 = bias_reg_L1
        self.bias_reg_L2 = bias_reg_L2
    
    def forward(self, inputs):
        # remember for backpropogation calculations
        self.inputs = inputs
        # calculate vals for neurons in this layer
        self.outputs = np.dot(inputs, self.weights) + self.biases
    
    def backward(self, dvals):
        # Param gradients
        self.dweights = np.dot(self.inputs.T, dvals)
        self.dbiases = np.sum(dvals, axis=0, keepdims=True)
        
        # Regularization gradients
        # L1
        if self.weight_reg_L1 > 0:
            # weights
            dL1_w = np.ones_like(self.weights)
            dL1_w[self.weights < 0] = -1
            self.dweights += self.weight_reg_L1 * dL1_w
            # biases
            dL1_b = np.ones_like(self.biases)
            dL1_b[self.biases < 0] = -1
            self.dbiases += self.bias_reg_L1 * dL1_b
        # L2
        if self.weight_reg_L2 > 0:
            # wieghts
            self.dweights += 2 * self.weight_reg_L2 * self.weights
            # biases
            self.dbiases += 2 * self.bias_reg_L2 * self.biases
        
        # Val gradients
        self.dinputs = np.dot(dvals, self.weights.T)

# Activation Classes
class Activation_ReLU:
    
    # Forward pass
    def forward(self, inputs):
        # Remember input values
        self.inputs = inputs
        # Calculate output values from inputs
        self.outputs = np.maximum(0, inputs)

    # Backward pass
    def backward(self, dvals):
        # Make a copy of values before modification
        self.dinputs = dvals.copy()
        # Zero gradient where input values were negative
        self.dinputs[self.inputs <= 0] = 0

# Softmax activation
class Activation_Softmax:
     
     # Forward pass
     def forward(self, inputs):
         # Remember input values
         self.inputs = inputs
         # Get unnormalized probabilities
         exp_values = np.exp(inputs - np.max(inputs, axis=1, keepdims=True))
         # Normalize them for each sample
         self.outputs = exp_values / np.sum(exp_values, axis=1, keepdims=True)
         
     # Backward pass
     def backward(self, dvals):
         # Create uninitialized array
         self.dinputs = np.empty_like(dvals)
         # Enumerate outputs and gradients
         for index, (single_output, single_dvals) in enumerate(zip(self.output, dvals)):
             # Flatten output array
             single_output = single_output.reshape(-1, 1)
             # Calculate Jacobian matrix of the output
             jacobian_matrix = np.diagflat(single_output) - np.dot(single_output, single_output.T)
             # Calculate sample-wise gradient
             # and add it to the array of sample gradients
             self.dinputs[index] = np.dot(jacobian_matrix, single_dvals)
             
# Optimizer
class Optimizer_SGD:

    def __init__(self, eta=1.0, decay=0.0, momentum=0.0):
        self.eta = eta
        self.current_eta = eta
        self.decay = decay
        self.momentum = momentum
        self.iterations = 0
    
    def pre_update_params(self):
        if self.decay:
            self.current_eta = self.eta * (1.0 / (1.0 + self.decay * self.iterations))
    
    def update_params(self, layer):
        # SGD w/ momentum
        if self.momentum:
            if not hasattr(layer, 'weight_momenta'):
                layer.weight_momenta = np.zeros_like(layer.weights)
                layer.bias_momenta = np.zeros_like(layer.biases)
            
            weight_updates = self.momentum * layer.weight_momenta - self.current_eta * layer.dweights
            layer.weight_momenta = weight_updates
            
            bias_updates = self.momentum * layer.bias_momenta - self.current_eta * layer.dbiases
            layer.bias_momenta = bias_updates
        # SGD w/o momentum
        else:
            weight_updates = -self.current_eta * layer.dweights
            bias_updates = -self.current_eta * layer.dbiases
        
        # Update
        layer.weights += weight_updates
        layer.biases += bias_updates
        
    def post_update_params(self):
        self.iterations += 1

# Adagrad optimizer
class Optimizer_Adagrad:
    # Initialize optimizer - set settings
    def __init__(self, eta=1.0, decay=0.0, epsilon=1e-7):
        self.eta = eta
        self.current_eta = eta
        self.decay = decay
        self.epsilon = epsilon
        self.iterations = 0

    # Call once before any parameter updates
    def pre_update_params(self):
        if self.decay:
            self.current_eta = self.eta * (1.0 / (1.0 + self.decay * self.iterations))

    # Update parameters
    def update_params(self, layer):
        # If layer does not contain cache arrays,
        # create them filled with zeros
        if not hasattr(layer, 'weight_cache'):
            layer.weight_cache = np.zeros_like(layer.weights)
            layer.bias_cache = np.zeros_like(layer.biases)

        # Update cache with squared current gradients
        layer.weight_cache += layer.dweights**2
        layer.bias_cache += layer.dbiases**2

        # Vanilla SGD parameter update + normalization
        # with square rooted cache
        layer.weights += -self.current_eta * layer.dweights / (np.sqrt(layer.weight_cache) + self.epsilon)
        layer.biases += -self.current_eta * layer.dbiases / (np.sqrt(layer.bias_cache) + self.epsilon)

    # Call once after any parameter updates
    def post_update_params(self):
        self.iterations += 1
            

# RMSprop optimizer
class Optimizer_RMSprop:
    # Initialize optimizer - set settings
    def __init__(self, eta=0.001, decay=0.0, epsilon=1e-7, rho=0.9):
        self.eta = eta
        self.current_eta = eta
        self.decay = decay
        self.epsilon = epsilon
        self.rho = rho
        self.iterations = 0

    # Call once before any parameter updates
    def pre_update_params(self):
        if self.decay:
            self.current_eta = self.eta * (1.0 / (1.0 + self.decay * self.iterations))

    # Update parameters
    def update_params(self, layer):
        # If layer does not contain cache arrays,
        # create them filled with zeros
        if not hasattr(layer, 'weight_cache'):
            layer.weight_cache = np.zeros_like(layer.weights)
            layer.bias_cache = np.zeros_like(layer.biases)

        # Update cache with squared current gradients
        layer.weight_cache = self.rho * layer.weight_cache + (1 - self.rho) * layer.dweights**2
        layer.bias_cache = self.rho * layer.bias_cache + (1 - self.rho) * layer.dbiases**2
        # Vanilla SGD parameter update + normalization
        # with square rooted cache
        layer.weights += -self.current_eta * layer.dweights / (np.sqrt(layer.weight_cache) + self.epsilon)
        layer.biases += -self.current_eta * layer.dbiases / (np.sqrt(layer.bias_cache) + self.epsilon)

    # Call once after any parameter updates
    def post_update_params(self):
        self.iterations += 1
 
 
 # Adam optimizer
class Optimizer_Adam:

    # Initialize optimizer - set settings
    def __init__(self, eta=0.001, decay=0.0, epsilon=1e-7, beta_1=0.9, beta_2=0.999):
        self.eta = eta
        self.current_eta = eta
        self.decay = decay
        self.iterations = 0
        self.epsilon = epsilon
        self.beta_1 = beta_1
        self.beta_2 = beta_2

    # Call once before any parameter updates
    def pre_update_params(self):
        if self.decay:
            self.current_eta = self.eta * (1.0 / (1.0 + self.decay * self.iterations))

    # Update parameters
    def update_params(self, layer):
        # If layer does not contain cache arrays,
        # create them filled with zeros
        if not hasattr(layer, 'weight_cache'):
            layer.weight_momenta = np.zeros_like(layer.weights)
            layer.weight_cache = np.zeros_like(layer.weights)
            layer.bias_momenta = np.zeros_like(layer.biases)
            layer.bias_cache = np.zeros_like(layer.biases)

        # Update momentum with current gradients
        layer.weight_momenta = self.beta_1 * layer.weight_momenta + (1 - self.beta_1) * layer.dweights
        layer.bias_momenta = self.beta_1 * layer.bias_momenta + (1 - self.beta_1) * layer.dbiases
        # Get corrected momentum
        # self.iteration is 0 at first pass
        # and we need to start with 1 here
        weight_momenta_corrected = layer.weight_momenta / (1 - self.beta_1 ** (self.iterations + 1))
        bias_momenta_corrected = layer.bias_momenta / (1 - self.beta_1 ** (self.iterations + 1))
        # Update cache with squared current gradients
        layer.weight_cache = self.beta_2 * layer.weight_cache + (1 - self.beta_2) * layer.dweights**2
        layer.bias_cache = self.beta_2 * layer.bias_cache + (1 - self.beta_2) * layer.dbiases**2
        # Get corrected cache
        weight_cache_corrected = layer.weight_cache / (1 - self.beta_2 ** (self.iterations + 1))
        bias_cache_corrected = layer.bias_cache / (1 - self.beta_2 ** (self.iterations + 1))
        # Vanilla SGD parameter update + normalization
        # with square rooted cache
        layer.weights += -self.current_eta * weight_momenta_corrected / (np.sqrt(weight_cache_corrected) + self.epsilon)
        layer.biases += -self.current_eta * bias_momenta_corrected / (np.sqrt(bias_cache_corrected) + self.epsilon)

    # Call once after any parameter updates
    def post_update_params(self):
        self.iterations += 1
    

# Common loss class
class Loss:

    # Regularization loss calculation
    def regularization_loss(self, layer):
        # 0 by default
        regularization_loss = 0
        # L1 regularization - weights
        # calculate only when factor greater than 0
        if layer.weight_reg_L1 > 0:
            regularization_loss += layer.weight_reg_L1 * np.sum(np.abs(layer.weights))
        # L2 regularization - weights
        if layer.weight_reg_L2 > 0:
            regularization_loss += layer.weight_reg_L2 * np.sum(layer.weights * layer.weights)
        # L1 regularization - biases
        # calculate only when factor greater than 0
        if layer.bias_reg_L1 > 0:
            regularization_loss += layer.bias_reg_L1 * np.sum(np.abs(layer.biases))
        # L2 regularization - biases
        if layer.bias_reg_L2 > 0:
            regularization_loss += layer.bias_reg_L2 * np.sum(layer.biases * layer.biases)
        
        return regularization_loss

    # Calculates the data and regularization losses
    # given model output and ground truth values
    def calculate(self, outputs, y):
        # Calculate sample losses
        sample_losses = self.forward(outputs, y)
        # Calculate mean loss
        data_loss = np.mean(sample_losses)
        # Return loss
        return data_loss


# Cross-entropy loss
class Loss_CategoricalCrossentropy(Loss):

    # Forward pass
    def forward(self, y_pred, y_true):
        # Number of samples in a batch
        n_samples = len(y_pred)
        # Clip data to prevent division by 0
        # Clip both sides to not drag mean towards any value
        y_pred_clipped = np.clip(y_pred, 1e-7, 1 - 1e-7)
        # Probabilities for target values -
        # only if categorical labels
        if len(y_true.shape) == 1:
            correct_confidences = y_pred_clipped[
                range(n_samples),
                y_true
            ]
        # Mask values - only for one-hot encoded labels
        elif len(y_true.shape) == 2:
            correct_confidences = np.sum(
                y_pred_clipped * y_true,
                axis=1
            )
        # Losses
        return -np.log(correct_confidences)

    # Backward pass
    def backward(self, dvalues, y_true):
        # Number of samples
        samples = len(dvalues)
        # Number of labels in every sample
        # We'll use the first sample to count them
        labels = len(dvalues[0])
        # If labels are sparse, turn them into one-hot vector
        if len(y_true.shape) == 1:
            y_true = np.eye(labels)[y_true]
        # Calculate gradient
        self.dinputs = -y_true / dvalues
        # Normalize gradient
        self.dinputs = self.dinputs / samples

# Softmax classifier - combined Softmax activation
# and cross-entropy loss for faster backward step
class Activation_Softmax_Loss_CategoricalCrossentropy():
    
    # Creates activation and loss function objects
    def __init__(self):
        self.activation = Activation_Softmax()
        self.loss = Loss_CategoricalCrossentropy()

    # Forward pass
    def forward(self, inputs, y_true):
        # Output layer's activation function
        self.activation.forward(inputs)
        # Set the output
        self.outputs = self.activation.outputs
        # Calculate and return loss value
        return self.loss.calculate(self.outputs, y_true)
    
    # Backward pass
    def backward(self, dvals, y_true):
        # Number of samples
        n_samples = len(dvals)
        # If labels are one-hot encoded,
        # turn them into discrete values
        if len(y_true.shape) == 2:
            y_true = np.argmax(y_true, axis=1)
        # Copy so we can safely modify
        self.dinputs = dvals.copy()
        # Calculate gradient
        self.dinputs[range(n_samples), y_true] -= 1
        # Normalize gradient
        self.dinputs = self.dinputs / n_samples

# CREATE DATASET & NEURAL NET
X, y = spiral_data(samples=1000, classes=3)

layer_1 = Layer_Dense(2, 51, weight_reg_L2=5e-4, bias_reg_L2=5e-4)
act_func_1 = Activation_ReLU()
layer_2 = Layer_Dense(51, 23)
act_func_2 = Activation_ReLU()
layer_3 = Layer_Dense(23, 7)
act_func_3 = Activation_ReLU()
layer_4 = Layer_Dense(7, 3)

act_loss_func = Activation_Softmax_Loss_CategoricalCrossentropy()

optimizer = Optimizer_Adam(eta=0.02, decay=5e-7)

for epoch in range(10001):
    layer_1.forward(X)
    act_func_1.forward(layer_1.outputs)
    layer_2.forward(act_func_1.outputs)
    act_func_2.forward(layer_2.outputs)
    layer_3.forward(act_func_2.outputs)
    act_func_3.forward(layer_3.outputs)
    layer_4.forward(act_func_3.outputs)
    
    data_loss = act_loss_func.forward(layer_4.outputs, y)
    regularization_loss = act_loss_func.loss.regularization_loss(layer_1) \
                        + act_loss_func.loss.regularization_loss(layer_2) \
                        + act_loss_func.loss.regularization_loss(layer_3) \
                        + act_loss_func.loss.regularization_loss(layer_4)
    loss = data_loss + regularization_loss
    
    predictions = np.argmax(act_loss_func.outputs, axis=1)
    if len(y.shape) == 2:
        y = np.argmax(y, axis=1)
    accuracy = np.mean(predictions == y)
    
    if not epoch % 100:
        print(f'epoch: {epoch}, ' +
            f'acc: {accuracy:.3f}, ' +
            f'loss: {loss:.3f} (' +
            f'data_loss: {data_loss:.3f}, ' +
            f'reg_loss: {regularization_loss:.3f}), ' +
            f'lr: {optimizer.current_eta}')

    act_loss_func.backward(act_loss_func.outputs, y)
    layer_4.backward(act_loss_func.dinputs)
    act_func_3.backward(layer_4.dinputs)
    layer_3.backward(act_func_3.dinputs)
    act_func_2.backward(layer_3.dinputs)
    layer_2.backward(act_func_2.dinputs)
    act_func_1.backward(layer_2.dinputs)
    layer_1.backward(act_func_1.dinputs)

    optimizer.pre_update_params()
    optimizer.update_params(layer_1)
    optimizer.update_params(layer_2)
    optimizer.update_params(layer_3)
    optimizer.update_params(layer_4)
    optimizer.post_update_params()
    
# Validate the model
# Create test dataset
X_test, y_test = spiral_data(samples=100, classes=3)

layer_1.forward(X_test)
act_func_1.forward(layer_1.outputs)
layer_2.forward(act_func_1.outputs)
act_func_2.forward(layer_2.outputs)
layer_3.forward(act_func_2.outputs)
act_func_3.forward(layer_3.outputs)
layer_4.forward(act_func_3.outputs)


loss = act_loss_func.forward(layer_4.outputs, y_test)

predictions = np.argmax(act_loss_func.outputs, axis=1)
if len(y_test.shape) == 2:
    y_test = np.argmax(y_test, axis=1)
accuracy = np.mean(predictions == y_test)
print(f'validation, acc: {accuracy:.3f}, loss: {loss:.3f}')