import numpy as np
import nnfs
from nnfs.datasets import spiral_data

nnfs.init()


# Layer
class Layer_Dense():
	
	def __init__(self, n_inputs, n_neurons):
		# init weights and biases
		self.weights = 0.01 * np.random.randn(n_inputs, n_neurons)
		self.biases = np.zeros((1, n_neurons))

	def forward(self, inputs):
		self.output = np.dot(inputs, self.weights) + self.biases

	
# Activation Functions
class Activation_ReLU():
	
	def forward(self, inputs):
		self.output = np.maximum(0, inputs)


class Activation_Softmax():
	
	def forward(self, inputs):
		# unnormalized probabilities
		exp_vals = np.exp(inputs - np.max(inputs, axis=1, keepdims=True))
		# normalized probabilities
		self.output = exp_vals / np.sum(exp_vals, axis=1, keepdims=True)


# Loss
class Loss():

	# Calculates the data and regularization losses
	# given model output (y_hat) and ground truth (y)
	def calculate(self, y_hat, y):
		sample_losses = self.forward(y_hat, y)
		return np.mean(sample_losses)


class Loss_CategoricalCrossEntropy(Loss):

	def forward(self, y_hat, y):
		# num samples in batch
		n_samples = len(y_hat)
		# clip data to prevent div by 0
		# clip both ends to avoid influence on mean
		y_hat_clipped = np.clip(y_hat, 1e-7, 1 - 1e-7)

		# probabilities for target vals
		#	when labels are categorical
		if len(y.shape) == 1:
			correct_confidences = y_hat_clipped[range(n_samples), y]
		#	when labels are one-hot encoded
		elif len(y.shape) == 2:
			correct_confidences = np.sum(y_hat_clipped*y, axis=1)

		# losses
		return -np.log(correct_confidences)


# Create Dataset
X, y = spiral_data(samples=100, classes=3)

# Create layer with 2 input features and 3 outputs & ReLU activation
layer_1 = Layer_Dense(2, 3)
act_func_1 = Activation_ReLU()

# Create layer with 3 inputs (from prev layer) and 3 outputs & Softmax activation
layer_2 = Layer_Dense(3, 3)
act_func_2 = Activation_Softmax()

# Create loss function
loss_func = Loss_CategoricalCrossEntropy()

# Forward pass
layer_1.forward(X)
act_func_1.forward(layer_1.output)
layer_2.forward(act_func_1.output)
act_func_2.forward(layer_2.output)

# Observe results
print(act_func_2.output[:5])

# Calculate loss
print(loss_func.calculate(act_func_2.output, y))

# Calculate accuracy
preds = np.argmax(act_func_2.output, axis=1)
if len(y.shape) == 2:
	y = np.argmax(y, axis=1)
print(np.mean(preds == y))
