# -----
# LAYER
class Layer_Dense:

	def __init__(self, inputs, neurons):
		self.weights = 0.01 * np.random.randn(inputs, neurons)
		self.biases = np.zeros((1, neurons))

	def forward(self, inputs):
		self.inputs = inputs	# used to determine partial derivs during backprop
		self.output = np.dot(inputs, self.weights) + self.biases

	def backward(self, dvals):
		# Gradients
		self.dweights = np.dot(self.inputs.T, dvals)
		self.dbiases = np.sum(dvals, axis=0, keepdims=True)
		# Gradient on values
		self.dinputs = np.dot(dvals, self.weights.T)

# ----------
# ACTIVATION
class Act_Func_ReLU:
	
	def forward(self, inputs):
		self.inputs = inputs
		self.output = np.maximum(0, inputs)

	def backward(self, dvals):
		self.dinputs = dvals.copy()
		# Gradient is zero for input of zero or less
		self.dinputs[self.inputs <= 0] = 0

class Act_Func_Softmax:
	
	def forward(self, inputs):
		pass

	# magic (?) [review Chap 9]
	def backward(self, dvals):
		# empty_like() doesn't zero out the array; more like an uninit-ed C++ array
		# can do this here, because all vals will be changed by the end of this function
		self.dinputs = np.empty_like(dvals)
		
		for index, (single_output, single_dvals) in enumerate(zip(self.output, dvals)):
			single_output = single_output.reshape(-1, 1)
			jacobian_matrix = np.diagflat(single_output) - np.dot(single_output, single.output.T)
			self.dinputs[index] = np.dot(jacobian_matrix, single_dvals)
			

# ----
# LOSS
class Loss:

	def calculate(self, y_hat, y):
		pass


class Loss_CategoricalCrossEntropy(Loss):

	def forward(self, y_hat, y):
		pass

	def backward(self, dvals, y):
		n_samples = len(dvals)
		n_labels = len(dvals[0])

		# one-hot vectorize if labels are spares (?)
		if len(y.shape) == 1:
			y = np.eye(labels)[y]

		# Calculate gradient
		self.dinputs = -y / dvals
		# Normalize
		self.dinputs = self.dinputs / n_samples	


# ----------
# ACT & LOSS
class Act_Func_SM_Loss_CCE:
	
	def __init__(self):
		self.act_func = Act_Func_Softmax()
		self.loss_func = Loss_CategoricalCrossEntropy()

	def forward(self, inputs, y):
		self.act_func(inputs)
		return self.loss_func.calculate(self.act_func.output, y)
		
	def backward(self, dvals, y):
		n_samples = len(dvals)
		if len(y.shape) == 2:
			y = np.argmax(y, axis=1)

		self.dinputs = dvals.copy()
		self.dinputs[range(n_samples), y] -= 1
		self.dinputs = self.dinputs / n_samples
