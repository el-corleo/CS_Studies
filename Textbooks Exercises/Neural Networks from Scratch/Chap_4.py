import numpy as np
import nnfs
from nnfs.datasets import spiral_data

nnfs.init()

# ReLU activation
class Activation_ReLU:
	
	# forward pass
	def forward(self, inputs):
		self.output = np.maximum(0, inputs)

class Layer_Dense:

	def __init__(self, n_inputs, n_neurons):
		self.weights = 0.01 * np.random.randn(n_inputs, n_neurons)
		self.biases = np.zeros((1, n_neurons))

	def forward(self, inputs):
		self.output = np.dot(inputs, self.weights) + self.biases

X, y = spiral_data(samples=100, classes=3)

dense1 = Layer_Dense(2, 3)

activation1 = Activation_ReLU()

dense1.forward(X)

activation1.forward(dense1.output)

print(activation1.output[:5])


#------------------------
# Softmax
import math

layer_outputs = [4.8, 1.21, 2.385]

exp_vals = []
for output in layer_outputs:
	exp_vals.append(math.e**output)
print('e^outputs')
print(exp_vals)

# exponentiation serves to make all values positive
# normalization flattens values to a number between 0 and 1

norm_base = sum(exp_vals)
norm_vals = []
for val in exp_vals:
	norm_vals.append(val/norm_base)

print('normalized e^outputs')
print(norm_vals)

# same using numpy
exp_vals = np.exp(layer_outputs)
norm_vals = exp_vals/np.sum(exp_vals) # why perform sum operation each time?

print(norm_vals)


#--------------------
# making the softmax compatible with layers

#exp_vals = np.exp(inputs)

# axis=1 means to sum by row
# keepdims=True means to output as column vector
#probabilities = exp_vals/np.sum(exp_vals, axis=1, keepdims=True)

# Softmax Activation
class Activation_Softmax:
	
	def forward(self, inputs):
		# subtraction done to mitigate value explosion and dead neurons
		exp_vals = np.exp(inputs - np.max(inputs, axis=1, keepdims=True))
		self.output = exp_vals/np.sum(exp_vals, axis=1, keepdims=True)


#---------------------
# Putting it all together
nnfs.init()

X, y = spiral_data(samples=100, classes=3)

dense1 = Layer_Dense(2, 3)

activation1 = Activation_ReLU()

dense2 = Layer_Dense(3, 3)

activation2 = Activation_Softmax()

dense1.forward(X)
activation1.forward(dense1.output)
dense2.forward(activation1.output)
activation2.forward(dense2.output)

print(activation2.output[:5])

