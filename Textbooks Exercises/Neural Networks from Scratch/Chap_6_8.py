# CHAP 6 OPTIMIZATION
# -------------------
import matplotlib.pyplot as plt
import nnfs
from nnfs.datasets import vertical_data

nnfs.init()

X, y = vertical_data(samples=100, classes=3)
plt.scatter(X[:, 0], X[:, 1], c=y, s=40, cmap='brg')
plt.show()


# NN code
import numpy as np

# Layer
class Layer_Dense():

	def __init__(self, n_inputs, n_neurons):
		self.weights = np.random.randn(n_inputs, n_neurons)
		self.biases = np.zeros((1, n_neurons))

	def forward_pass(self, inputs):
		self.output = np.dot(inputs, self.weights) + self.biases

# Act Funcs
class Act_Func_ReLU():
	
	def forward_pass(self, inputs):
		self.output = np.maximum(0, inputs)

class Act_Func_Softmax():

	def forward_pass(self, inputs):
		exp_vals = np.exp(inputs - np.max(inputs, axis=1, keepdims=True)
		self.output = exp_vals / np.sum(exp_vals, axis=1, keepdims=True)

# Loss
class Loss():

	def calculate(self, y_hat, y):
		sample_losses = self.forward(y_hat, y)
		return np.mean(sample_losses)

class Loss_CategoricalCrossEntropy(Loss):

	def forward_pass(self, y_hat, y):
		n_samples = len(y_hat)
		
		y_hat_clipped = np.clip(y_hat, 1e-7, 1 - 1e-7)
		
		if len(y.shape) == 1:
			correct_confidences = y_hat_clipped[range(n_samples), y]
		elif len(y.shape) == 2:
			correct_confidences = np.sum(y_hat_clipped*y, axis=1)

		return -np.log(correct_confidences)


# Create dataset
X, y = vertical_data(samples=100, classes=3)

# Create model
layer_1 = Layer_Dense(2, 3)
act_func_1 = Act_Func_ReLU()
layer_2 = Layer_Dense(3, 3)
act_func_2 = Act_Func_Softmax()

# Create loss func
loss_func = Loss_CategoricalCrossEntropy()

# Misc setup vars
lowest_loss = 9999999 # some init val
best_dense1_weights = layer_1.weights.copy()
best_dense1_biases = layer_1.biases.copy()
best_dense2_weights = layer_2.weights.copy()
best_dense2_biases = layer_2.biases.copy()



# CHAP 7 DERIVATIVES
# ------------------
# Basic calculus rule for derivatives


# CHAP 8 PARTIAL DERIVATIVES/GRADIENTS
# ------------------------------------
# A partial derivative assumes all other variables are constants and takes the derivative only with respect to a single variable
# Gradient is a vector containing all partial derivatives
