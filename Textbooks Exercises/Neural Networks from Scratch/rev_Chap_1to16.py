import numpy as np
import nnfs
from nnfs.datasets import spiral_data

nnfs.init()

class Layer_Dense:

	def __init__(self, n_inputs, n_neurons, 
			weight_reg_l1=0, weight_reg_l2=0,
			bias_reg_l1=0, bias_reg_l2=0):
		
		self.weights = 0.01 * np.random.randn(n_inputs, n_neurons)
		self.biases = np.zeros((1, n_neurons))
		self.weight_reg_l1 = weight_reg_l1
		self.weight_reg_l2 = weight_reg_l2
		self.bias_reg_l1 = bias_reg_l1
		self.bias_reg_l2 = bias_reg_l2
	
	def forward(self, inputs):
		self.inputs = inputs
		self.outputs = np.dot(inputs, self.weights) + self.biases

	def backward(self, dvals):
		self.dweights = np.dot(self.inputs.T, dvals)
		self.dbiases = np.sum(dvals, axis=0, keepdims=True)
		
		if self.weight_reg_l1 > 0:
			dL1 = np.ones_like(self.weights)
			dL1[self.weights < 0] = -1
			self.dweights += self.weight_reg_l1 * dL1
		if self.weight_reg_l2 > 0:
			self.dweights += 2 * self.weight_reg_l2 * self.weights

		if self.bias_reg_l1 > 0:
			dL1 = np.ones_like(self.biases)
			dL1[self.biases < 0] = -1
			self.dbiases += self.bias_reg_l1 * dL1
		if self.bias_reg_l2 > 0:
			self.dbiases += 2 * self.bias_reg_l2 * self.biases

		self.dinputs = np.dot(dvals, self.weights.T)

class Layer_Dropout:

	def __init__(self, rate):
		# Stores rate of neurons to keep active
		self.rate = 1 - rate

	def forward(self, inputs):
		self.inputs = inputs
		self.binary_mask = np.random.binomial(1, self.rate, size=inputs.shape) / self.rate
		self.outputs = inputs * self.binary_mask

	def backward(self, dvals):
		self.dinputs = dvals * self.binary_mask

class Activation_ReLU:

	def forward(self, inputs):
		self.inputs = inputs
		self.outputs = np.maximum(0, inputs)

	def backward(self, dvals):
		self.dinputs = dvals.copy()
		self.dinputs[self.inputs <= 0] = 0

class Activation_Softmax:

	def forward(self, inputs):
		self.inputs = inputs
		exp_vals = np.exp(inputs - np.max(inputs, axis=1, keepdims=True))
		self.outputs = exp_vals / np.sum(exp_vals, axis=1, keepdims=True)

	def backward(self, dvals):
		self.dinputs = np.empty_like(dvals)
		for index, (single_output, single_dval) in enumerate(zip(self.outputs, dvals)):
			single_output = single_output.reshape(-1, 1)
			jacobian_matrix = np.diagflat(single_output) - np.dot(single_output, single_output.T)
			self.dinputs[index] = np.dot(jacobian_matrix, single_dvals)


class Activation_Sigmoid:

	def forward(self, inputs):
		self.inputs = inputs
		self.outputs = 1 / (1 + np.exp(-inputs))

	def backward(self, dvals):
		self.dinputs = dvals * (1 - self.outputs) * self.outputs


class Optimizer_SGD:
	pass

class Optimizer_AdaGrad:
	pass

class Optimizer_RMSProp:
	pass

class Optimizer_Adam:
	
	def __init__(self, delta_eta=0.001, decay=0.0, epsilon=1e-7, beta_1=0.9, beta_2=0.999):
		self.delta_eta = delta_eta
		self.current_eta = delta_eta
		self.decay = decay
		self.iterations = 0 
		self.epsilon = epsilon
		self.beta_1 = beta_1
		self.beta_2 = beta_2

	def pre_update_params(self):
		if self.decay:
			self.current_eta = self.delta_eta * (1.0 / (1.0 + self.decay * self.iterations))

	def update_params(self, layer):
		if not hasattr(layer, "weight_cache"):
			layer.weight_momenta = np.zeros_like(layer.weights)
			layer.weight_cache = np.zeros_like(layer.weights)
			layer.bias_momenta = np.zeros_like(layer.biases)
			layer.bias_cache = np.zeros_like(layer.biases)

		layer.weight_momenta = self.beta_1 * layer.weight_momenta + (1 - self.beta_1) * layer.dweights
		layer.bias_momenta = self.beta_1 * layer.bias_momenta + (1 - self.beta_1) * layer.dbiases

		corrected_weight_momenta = layer.weight_momenta / (1 - self.beta_1 ** (self.iterations+1))
		corrected_bias_momenta = layer.bias_momenta / (1 - self.beta_1 ** (self.iterations+1))


		layer.weight_cache = self.beta_2 * layer.weight_cache + (1 - self.beta_2) * layer.dweights**2
		layer.bias_cache = self.beta_2 * layer.bias_cache + (1 - self.beta_2) * layer.dbiases**2

		corrected_weight_cache = layer.weight_cache / (1 - self.beta_2 ** (self.iterations+1))
		corrected_bias_cache = layer.bias_cache / (1 - self.beta_2 ** (self.iterations+1))

		layer.weights += -self.current_eta * corrected_weight_momenta / np.sqrt(corrected_weight_cache) + self.epsilon
		layer.biases += -self.current_eta * corrected_bias_momenta / np.sqrt(corrected_bias_cache) + self.epsilon

	def post_update_params(self):
		self.iterations += 1

class Loss:

	def regularization_loss(self, layer):
		reg_loss = 0
		if layer.weight_reg_l1 > 0:
			reg_loss += layer.weight_reg_l1 * np.sum(np.abs(layer.weights))
		if layer.weight_reg_l2 > 0:
			reg_loss += layer.weight_reg_l2 * np.sum(layer.weights * layer.weights)

		if layer.bias_reg_l1 > 0:
			reg_loss += layer.bias_reg_l1 * np.sum(np.abs(layer.biases))
		if layer.bias_reg_l2 > 0:
			reg_loss += layer.bias_reg_l2 * np.sum(layer.biases * layer.biases)

		return reg_loss

	def calculate(self, y_hat, y):
		sample_losses = self.forward(y_hat, y)
		return np.mean(sample_losses)

class Loss_CategoricalCrossentropy(Loss):
	
	def forward(self, y_hat, y):
		n_samples = len(y_hat)

		clipped_y_hat = np.clip(y_hat, 1e-7, 1-1e-7)
		
		if len(y.shape) == 1:
			correct_confidences = clipped_y_hat[range(n_samples), y]
		elif len(y.shape) == 2:
			correct_confidences = np.sum(clipped_y_hat * y, axis=1)

		return -np.log(correct_confidences)

	def backward(self, dvals, y):
		n_samples = len(dvals)
		n_labels = len(dvals[0])

		if len(y.shape) == 1:
			y = np.eye(n_labels)[y]

		self.dinputs = -y / dvals
		self.dinputs = self.dinputs / n_samples

class Activation_SM_Loss_CC:
	
	def __init__(self):
		self.activation = Activation_Softmax()
		self.loss = Loss_CategoricalCrossentropy()

	def forward(self, inputs, y):
		self.activation.forward(inputs)
		self.outputs = self.activation.outputs
		return self.loss.calculate(self.outputs, y)

	def backward(self, dvals, y):
		n_samples = len(dvals)
		
		if len(y.shape) == 2:
			y = np.argmax(y, axis=1)

		self.dinputs = dvals.copy()
		self.dinputs[range(n_samples), y] -= 1
		self.dinputs = self.dinputs / n_samples

class Loss_BinaryCrossentropy(Loss):
	
	def forward(self, y_hat, y):
		clipped_y_hat = np.clip(y_hat, 1e-7, 1-1e-7)
		sample_losses = -(y * np.log(clipped_y_hat) + (1 - y_hat) * np.log(1 - clipped_y_hat))
		return np.mean(sample_losses, axis=1)

	def backward(self, dvals, y):
		n_samples = len(dvals)
		n_outputs = len(dvals[0])

		clipped_dvals = np.clip(dvals, 1e-7, 1-1e-7)
		
		self.dinputs = -(y / clipped_dvals - (1 - y) / (1 - clipped_dvals)) / n_outputs
		self.dinputs = self.dinputs / n_samples

# ------------------------------------------------------

X, y = spiral_data(samples=100, classes=2)

y = y.reshape(-1, 1)

layer_1 = Layer_Dense(2, 64, weight_reg_l2=5e-4, bias_reg_l2=5e-4)
act_func_1 = Activation_ReLU()
layer_2 = Layer_Dense(64, 1)
act_func_2 = Activation_Sigmoid()

loss_func = Loss_BinaryCrossentropy()

optimizer = Optimizer_Adam(decay=5e-6)

for epoch in range(10001):
	layer_1.forward(X)
	act_func_1.forward(layer_1.outputs)
	layer_2.forward(act_func_1.outputs)
	act_func_2.forward(layer_2.outputs)
	
	data_loss = loss_func.calculate(act_func_2.outputs, y)
	reg_loss = loss_func.regularization_loss(layer_1) + loss_func.regularization_loss(layer_2)

	loss = data_loss = reg_loss

	predictions = (act_func_2.outputs > 0.5) * 1
	accuracy = np.mean(predictions == y)
	
	if epoch % 100 == 0:
		print(f"epoch: {epoch}, acc: {accuracy:.3f}, loss: {loss:.3f} (data_loss= {data_loss:.3f}, reg_loss: {reg_loss:.3f}), eta: {optimizer.current_eta}")

	loss_func.backward(act_func_2.outputs, y)
	act_func_2.backward(loss_func.dinputs)
	layer_2.backward(act_func_2.dinputs)
	act_func_1.backward(layer_2.dinputs)
	layer_1.backward(act_func_1.dinputs)

	optimizer.pre_update_params()
	optimizer.update_params(layer_1)
	optimizer.update_params(layer_2)
	optimizer.post_update_params()

X_test, y_test = spiral_data(samples=1000, classes=2)
y_test = y_test.reshape(-1, 1)

layer_1.forward(X_test)
act_func_1.forward(layer_1.outputs)
layer_2.forward(act_func_1.outputs)
act_func_2.forward(layer_2.outputs)
loss = loss_func.calculate(act_func_2.outputs, y_test)	

predictions = (act_func_2.outputs > 0.5) * 1
accuracy = np.mean(predictions == y_test)

print(f"validation, acc: {accuracy:.3f}, loss: {loss:.3f}")

