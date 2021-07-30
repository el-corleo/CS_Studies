import numpy as np
import nnfs
from nnfs.datasets import spiral_data

class Layer_Dense:
	
	def __init__(self, n_inputs, n_neurons):
		self.weights = 0.01 * np.random.randn(n_inputs, n_neurons)
		self.biases = np.zeros((1, n_neurons))

	def forward(self, inputs):
		self.inputs = inputs
		self.output = np.dot(inputs, self.weights) + self.biases

	def backward(self, dvals):
		self.dweights = np.dot(self.inputs.T, dvals)
		self.dbiases = np.sum(dvals, axis=0, keepdims=True)
		self.dinputs = np.dot(dvals, self.dweights.T)


class Act_Func_ReLU:

	def forward(self, inputs):
		self.inputs = inputs
		self.output = np.maximum(0, inputs)

	def backward(self, dvals):
		self.dinputs = dvals.copy()
		self.dinputs[self.inputs <= 0] = 0

class Act_Func_Softmax():
	
	def forward(self, inputs):
		self.inputs = inputs
		exp_vals = np.exp(inputs - np.max(inputs, axis=1, keepdims=True))
		self.output = exp_vals / np.sum(exp_vals, axis=1, keepdims=True)

	def backward(self, dvals):
		self.dinputs = np.empty_like(dvals)
		for index, (single_output, single_dval) in enumerate(zip(self.output, dvals)):
			single_output = single_output.reshape(-1, 1)
			jacobian_mat = np.diagflat(single_output) - np.dot(single_output, single_output.T)
			self.dinputs[index] = np.dot(jacobian_mat, single_dvals)


class Loss:

	def calculate(self, output, y):
		sample_losses = self.forward(output, y)
		return np.mean(sample_losses)


class Loss_CategoricalCrossEntropy(Loss):
	
	def forward(self, y_hat, y):
		n_samples = len(y_hat)
		y_hat_clipped = np.clip(y_hat, 1e-7, 1 - 1e-7)
		if len(y.shape) == 1:
			correct_confidences = y_hat_clipped[range(n_samples), y]
		elif len(y.shape) == 2:
			correct_confidences = np.sum(y_hat_clipped * y, axis=1)

		return -np.log(correct_confidences)

	def backward(self, dvals, y):
		n_samples = len(dvals)
		n_labels = len(dvals[0])

		if len(y.shape) == 1:
			y = np.eye(n_labels)[y]

		self.dinputs = -y / dvals
		self.dinputs = self.dinputs / n_samples


class Act_Loss_Func_SMCCE:
	
	def __init__(self):
		self.act_func = Act_Func_Softmax()
		self.loss_func = Loss_CategoricalCrossEntropy()

	def forward(self, inputs, y):
		self.act_func.forward(inputs)
		self.output = self.act_func.output
		return self.loss_func.calculate(self.output, y)

	def backward(self, dvals, y):
		n_samples = len(dvals)
		if len(y.shape) == 2:
			y = np.argmax(y, axis=1)

		self.dinputs = dvals.copy()
		self.dinputs[range(n_samples), y] -= 1
		self.dinputs = self.dinputs / n_samples


X, y = spiral_data(samples=100, classes=3)

layer_1 = Layer_Dense(2, 3)
act_func_1 = Act_Func_ReLU()
layer_2 = Layer_Dense(3, 3)
act_loss_func = Act_Loss_Func_SMCCE()

# Forward pass
layer_1.forward(X)
act_func_1.forward(layer_1.output)
layer_2.forward(act_func_1.output)
loss = act_loss_func.forward(layer_2.output, y)

print(act_loss_func.output[:5])
print('loss:', loss)

predictions = np.argmax(act_loss_func.output, axis=1)
if len(y.shape) == 2:
	y = np.argmax(y, axis=1)
accuracy = np.mean(predictions == y)

print('acc:', accuracy)

# Backward pass
act_loss_func.backward(act_loss_func.output, y)
layer_2.backward(act_loss_func.dinputs)
act_func_1.backward(layer_2.dinputs)
layer_1.backward(act_func_1.dinputs)

print(layer_1.dweights)
print(layer_1.dbiases)
print(layer_2.dweights)
print(layer_2.dbiases)
