import numpy as np
import nnfs
from nnfs.datasets import spiral_data


class Layer_Dense:
	
	def __init__(self, n_inputs, n_neurons):
		self.weights = 0.01 * np.random.randn(n_inputs, n_neurons)
		self.biases = np.zeros((1, n_neurons))

	def forward(self, inputs):
		# saved for use in backprop
		self.inputs = inputs
		self.outputs = np.dot(inputs, self.weights) + self.biases

	def backward(self, dvalues):
		self.dweights = np.dot(self.inputs.T, dvalues)
		self.dbiases = np.sum(dvalues, axis=0, keepdims=True)
		# why keep this?
		self.dinputs = np.dot(dvalues, self.weights.T)


class Activation_ReLU:

	def forward(self, inputs):
		# saved for use in backprop
		self.inputs = inputs
		self.outputs = np.maximum(0, inputs)

	def backward(self, dvalues):
		# why make a copy?
		self.dinputs = dvalues.copy()
		self.dinputs[self.inputs <= 0] = 0


class Activation_Softmax:

	def forward(self, inputs):
		# saved for use in backprop
		self.inputs = inputs
		# subtract max to force exponent into range of (-inf, 0]
		# this keeps value between (0-1]
		exp_values = np.exp(inputs - np.max(inputs, axis=1, keepdims=True))
		# normalized values
		self.outputs = exp_values / np.sum(exp_values, axis=1, keepdims=True)

	def backward(self, dvalues):
		self.dinputs = np.empty_like(dvalues)
		for index, (single_input, single_dvalues) in enumerate(zip(self.outputs, dvalues)):
			single_outputs = single_outputs.reshape(-1, 1)
			jacobian_matrix = np.diagflat(single_output) - np.dot(single_output, single_output.T)
			self.dinputs[index] = np.dot(jacobian_matrix, single_dvalues)


class Loss:

	def calculate(self, y_hat, y):
		sample_losses = self.forward(y_hat, y)
		batch_loss = np.mean(sample_losses)
		return batch_loss


class Loss_CategoricalCrossEntropy(Loss):

	def forward(self, y_hat, y):
		n_samples = len(y_hat)
		y_hat_clipped = np.clip(y_hat, 1e-7, 1 - 1e-7)
		# for list of labels as indexes
		if len(y.shape) == 1:
			correct_confidences = y_hat_clipped[range(n_samples), y]
		# for matrix of labels as one-hot encoded
		elif len(y.shape) == 2:
			correct_confidences = np.sum(y_hat_clipped * y, axis=1)
		# losses
		return -np.log(correct_confidences)

	def backward(self, dvalues, y):
		n_samples = len(dvalues)
		n_labels = len(y)
		# convert labels to one-hot if needed
		if len(y.shape) == 1:
			y = np.eye(n_labels)[y]
		# gradient
		self.dinputs = -y / dvalues
		# normalized gradient
		self.dinputs = self.dinputs / n_samples


class Activation_Softmax_Loss_CategoricalCrossentropy():
	
	def __init__(self):
		self.activation = Activation_Softmax()
		self.loss = Loss_CategoricalCrossEntropy()

	# Forward pass
	def forward(self, inputs, y):
		# Output layer’s activation function
		self.activation.forward(inputs)
		# Set the output
		self.outputs = self.activation.outputs
		# Calculate and return loss value
		return self.loss.calculate(self.outputs, y)

	# Backward pass
	def backward(self, dvalues, y):
		# Number of samples
		n_samples = len(dvalues)
		# If labels are one-hot encoded,
		# turn them into discrete values
		if len(y.shape) == 2:
			y = np.argmax(y, axis=1)
		# Copy so we can safely modify
		self.dinputs = dvalues.copy()
		# Calculate gradient
		self.dinputs[range(n_samples), y] -= 1
		# Normalize gradient
		self.dinputs = self.dinputs / n_samples


# The optimizer manipulates the learning rate
# Then it updates weights and biases per layer
class Optimizer_SGD:
	
	def __init__(self, starting_learning_rate=1.0, decay_rate=0.0001, momentum=0.0):
		self.learning_rate = starting_learning_rate
		self.decay_rate = decay_rate
		self.momentum = momentum

	def update_params(self, layer):
		if self.momentum:
			# create weights momenta if they don't already exist
			if not hasattr(layer, 'weights_momenta'):
				layer.weights_momenta = np.zeros_like(layer.weights)
				layer.biases_momenta = np.zeros_like(layer.biases)

			updated_weights = self.momentum * layer.weights_momenta - self.learning_rate * layer.dweights
			updated_biases = self.momentum * layer.biases_momenta - self.learning_rate * layer.dbiases
		else:
			updated_weights = -self.learning_rate * layer.dweights
			updated_biases = -self.learning_rate * layer.dbiases
		
		layer.weights += updated_weights
		layer.biases += updated_biases

	def decay_learning_rate(self):
		# decays by fixed amt each iteration
		# also possible to decay by ever decreasing amt
		if self.learning_rate - self.decay_rate > 0:
			self.learning_rate -= self.decay_rate

# Adaptive Gradient - changes gradient based on normalized squared sum of previous gradients
class Optimizer_AdaGrad():

	def __init__(self, starting_learning_rate=1.0, decay_rate=0.0001, epsilon=1e-7):
		self.learning_rate = starting_learning_rate
		self.decay_rate = decay_rate
		self.epsilon = epsilon

	def update_params(self, layer):
		# create weights cache if they don't exist
		if not hasattr(layer, 'weights_cache'):
			layer.weights_cache = np.zeros_like(layer.weights)
			layer.biases_cache = np.zeros_like(layer.biases)

		layer.weights_cache += layer.dweights**2
		layer.biases_cache += layer.dbiases**2

		layer.weights += -self.learning_rate * layer.dweights / (np.sqrt(layer.weights_cache) + self.epsilon)
		layer.biases += -self.learning_rate * layer.dbiases / (np.sqrt(layer.biases_cache) + self.epsilon)
		
	def decay_learning_rate(self):
		# decays by fixed amt each iteration
		# also possible to decay by ever decreasing amt
		if self.learning_rate - self.decay_rate > 0:
			self.learning_rate -= self.decay_rate


# cache is not the squared sum of previous gradients, but a fluctuating average
class Optimizer_RMSProp:

	def __init__(self, learning_rate=0.001, decay_rate=0.0, epsilon=1e-7, rho=0.9):
		self.learning_rate = learning_rate
		self.curr_learning_rate = learning_rate
		self.iterations = 0
		self.decay_rate = decay_rate
		self.epsilon = epsilon
		self.rho = rho

	def update_params(self, layer):
		# create weights cache if they don't exist
		if not hasattr(layer, 'weights_cache'):
			layer.weights_cache = np.zeros_like(layer.weights)
			layer.biases_cache = np.zeros_like(layer.biases)

		layer.weights_cache = self.rho * layer.weights_cache + (1 - self.rho) * layer.dweights ** 2
		layer.biases_cache = self.rho * layer.biases_cache + (1 - self.rho) * layer.dbiases ** 2

		layer.weights += -self.learning_rate * layer.dweights / (np.sqrt(layer.weights_cache) + self.epsilon)
		layer.biases += -self.learning_rate * layer.dbiases / (np.sqrt(layer.biases_cache) + self.epsilon)
		
	def decay_learning_rate(self):
		# decays by fixed amt each iteration
		# also possible to decay by ever decreasing amt
		if self.decay_rate:
			self.curr_learning_rate = self.learning_rate * (1.0 / (1.0 + self.decay_rate * self.iterations))
			self.iterations += 1


class Optimizer_Adam:

    def __init__(self, learning_rate=0.001, decay_rate=0.0, epsilon=1e-7, beta_1=0.9, beta_2=0.999):
        self.learning_rate = learning_rate
        self.current_learning_rate = learning_rate
        self.decay_rate = decay_rate
        self.iterations = 0
        self.epsilon = epsilon
        self.beta_1 = beta_1
        self.beta_2 = beta_2
        
    def update_params(self, layer):
        if not hasattr(layer, 'weights_cache'):
            layer.weights_momenta = np.zeros_like(layer.weights)
            layer.weights_cache = np.zeros_like(layer.weights)
            layer.biases_momenta = np.zeros_like(layer.biases)
            layer.biases_cache = np.zeros_like(layer.biases)
            
        layer.weights_momenta = self.beta_1 * layer.weights_momenta + (1 - self.beta_1) * layer.dweights
        layer.biases_momenta = self.beta_1 * layer.biases_momenta + (1 - self.beta_1) * layer.dbiases
        
        weights_momenta_corrected = layer.weights_momenta / (1 - self.beta_1 ** (self.iterations+1))
        biases_momenta_corrected = layer.biases_momenta / (1 - self.beta_1 ** (self.iterations+1))
        
        layer.weights_cache = self.beta_2 * layer.weights_cache + (1 - self.beta_2) * layer.dweights**2
        layer.biases_cache = self.beta_2 * layer.biases_cache + (1 - self.beta_2) * layer.dbiases**2
        
        weights_cache_corrected = layer.weights_cache / (1 - self.beta_2 ** (self.iterations+1))
        biases_cache_corrected = layer.biases_cache / (1 - self.beta_2 ** (self.iterations+1))
        
        layer.weights += -self.learning_rate * weights_momenta_corrected / (np.sqrt(weights_cache_corrected) + self.epsilon)
        layer.biases += -self.learning_rate * biases_momenta_corrected / (np.sqrt(biases_cache_corrected) + self.epsilon)
        
    def decay_learning_rate(self):
        if self.decay_rate:
            self.curr_learning_rate = self.learning_rate * (1.0 / (1.0 + self.decay_rate * self.iterations))
            self.iterations += 1


# -------------------------------------
# create network
X, y = spiral_data(samples=1000, classes=3)

layer_1 = Layer_Dense(2, 64)
act_func_1 = Activation_ReLU()
layer_2 = Layer_Dense(64, 32)
act_func_2 = Activation_ReLU()
layer_3 = Layer_Dense(32, 3)
act_loss_func = Activation_Softmax_Loss_CategoricalCrossentropy()
#optimizer = Optimizer_SGD(momentum=0.9)
#optimizer = Optimizer_AdaGrad()
#optimizer = Optimizer_RMSProp(learning_rate=0.02, decay_rate=1e-5, rho=0.999)
optimizer = Optimizer_Adam(learning_rate=0.05, decay_rate=5e-7)

for epoch in range(10001):
	# forward pass
	layer_1.forward(X)
	act_func_1.forward(layer_1.outputs)
	layer_2.forward(act_func_1.outputs)
	act_func_2.forward(layer_2.outputs)
	layer_3.forward(act_func_2.outputs)	
	loss = act_loss_func.forward(layer_3.outputs, y)

	# display results
	predictions = np.argmax(act_loss_func.outputs, axis=1)
	if len(y.shape) == 2:
		y = np.argmax(y, axis=1)
	accuracy = np.mean(predictions==y)
	if not epoch % 100:	# updates every 100 epochs
		print(f'epoch: {epoch}, acc: {accuracy:.3f}, loss: {loss:.3f}, eta: {optimizer.learning_rate:.3f}')

	# backward pass
	act_loss_func.backward(act_loss_func.outputs, y)
	layer_3.backward(act_loss_func.dinputs)
	act_func_2.backward(layer_3.dinputs)
	layer_2.backward(act_func_2.dinputs)
	act_func_1.backward(layer_2.dinputs)
	layer_1.backward(act_func_1.dinputs)

	# optimize
	optimizer.update_params(layer_1)
	optimizer.update_params(layer_2)
	optimizer.update_params(layer_3)
	optimizer.decay_learning_rate()
