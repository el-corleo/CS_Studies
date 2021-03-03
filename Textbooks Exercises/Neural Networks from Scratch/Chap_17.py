import matplotlib.pyplot as plt
import nnfs
from nnfs.datasets import sine_data

nnfs.init()

X, y = sine_data()

plt.plot(X, y)
plt.show()


class Activation_Linear:

	def forward(self, inputs):
		self.inputs = inputs
		self.outputs = inputs

	def backward(self, dvals):
		self.dinputs = dvals.copy()

class Loss_MeanSquaredError(Loss):

	def forward(self, y, y_hat):
		return np.mean((y-y_hat)**2, axis=1)
		
	def backward(self, dvals, y):
		n_samples = len(dvals)
		n_outputs = len(dvals[0])

		self.dinputs = -2 * (y - dvals) / n_outputs
		self.dinputs = self.dinputs / n_samples

class Loss_MeanAbsoluteError(Loss):

	def forward(self, y, y_hat):
		return np.mean(np.abs(y - y_hat), axis=1)

	def backward(self, dvals, y):
		n_samples = len(dvals)
		n_outputs = len(dvals[0])

		self.dinputs = np.sign(y - dvals) / n_outputs
		self.dinputs = self.dinputs / n_samples









