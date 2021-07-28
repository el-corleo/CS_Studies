# L1 regularization is the sum of the absolute values of all the weights and biases
# L2 regularization is the squared sum of all these values
# Only used on hidden layers typically

class Layer_Dense:

	def __init__(self, n_inputs, n_neurons, w_reg_l1=0, w_reg_l2=0, b_reg_l1=0, b_reg_l2=0):
		# initialize weights
        self.weights = 0.01 * np.random.randn(n_inputs, n_neurons)
        self.biases = np.zeros([1, n_neurons])
        # set regularization strength
        self.w_reg_l1 = w_reg_l1
        self.w_reg_l2 = w_reg_l2
        self.b_reg_l1 = b_reg_l1
        self.b_reg_l2 = b_reg_l2

    # ...
    
    def backward(self, dvals):
        self.dweights = np.dot(self.inputs.T, dvals)
        self.dbiases = np.sum(dvals, axis=0, keepdims=True)
        
        if self.w_reg_l1 > 0:
            dL1 = np.ones_like(self.weights)
            dL1[self.weights < 0] = -1
            self.dweights += self.w_reg_l1 * dL1
        if self.w_reg_l2 > 0:
            self.dweights += 2 * self.w_reg_l2 * self.weights
        
        if self.b_reg_l1 > 0:
            dL1 = np.ones_like(self.biases)
            dL1[self.biases < 0] = -1
            self.dbiases += self.b_reg_l1 * dL1
        if self.b_reg_l2 > 0:
            self.biases += 2 * self.b_reg_l2 * self.biases
            
        self.dinputs = np.dot(dvals, self.weights.T)


class Loss:
    
    def regularization_loss(self, layer):
        """"Only calculates regularization if parameters have been set in the layer"""
        reg_loss = 0
        
        if layer.w_reg_l1 > 0:
            reg_loss += layer.w_reg_l1 * np.sum(np.abs(layer.weights))
            
        if layer.w_reg_l2 > 0:
            reg_loss += layer.w_reg_l2 * np.sum(layer.weights * layer.weights)
        
        if layer.b_reg_l1 > 0:
            reg_loss += layer.w_reg_l1 * np.sum(np.abs(layer.biases))
        
        if layer.b_reg_l2 > 0:
            reg_loss += layer.w_reg_l2 * np.sum(layer.biases * layer.biases)
            
        return reg_loss
        
# in the training loop we'd add
data_loss = loss_func.forward(act_func_2.output, y)
reg_loss = loss_func.regularization_loss(layer_1) + loss_func.regularization_loss(layer_2)

loss = data_loss + reg_loss

# add to print out
print(f'epoch: {epoch}, ' +
    f'acc: {accuracy:.3f}, ' +
    f'loss: {loss:.3f} (' +
    f'data_loss: {data_loss:.3f}, ' +
    f'reg_loss: {regularization_loss:.3f}), ' +
    f'lr: {optimizer.current_learning_rate}')
 
# Create Dense layer with 2 input features and 3 output values
dense1 = Layer_Dense(2, 64, weight_regularizer_l2=5e-4,
bias_regularizer_l2=5e-4)