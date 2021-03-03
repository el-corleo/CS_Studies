# BACKPROPAGATION
# ----------------
# Forward pass
x = [1.0, -2.0, 3.0] # input values
w = [-3.0, -1.0, 2.0] # weights
b = 1.0 # bias

# Multiplying inputs by weights
xw0 = x[0] * w[0]
xw1 = x[1] * w[1]
xw2 = x[2] * w[2]

# Adding weighted inputs and a bias
z = xw0 + xw1 + xw2 + b

# ReLU activation function
y = max(z, 0)


# Backward pass
# Derivative from the next layer
dval = 1.0

# Derivative of ReLU and chain rule
drelu_dz = dval * (1.0 if z > 0 else 0.0)

# Partial derivatives of sum of inputs * weights + bias
dsum_dxw0 = 1				# partial derivative of sum is always 1
drelu_dxw0 = drelu_dz * dsum_dxw0	# chain rule
dsum_dxw1 = 1
drelu_dxw1 = drelu_dz * dsum_dxw1
dsum_dxw2 = 1
drelu_dxw2 = drelu_dz * dsum_dxw2
dsum_db = 1
drelu_db = drelu_dz * dsum_db

# Partial derivatives of individual weights and inputs
dmul_dx0 = w[0]				# partial deriv of input * weight wrt input is the weight
dmul_dx1 = w[1]
dmul_dx2 = w[2]
dmul_dw0 = x[0]				# partial deriv of input * weight wrt weight is the input
dmul_dw1 = x[1]
dmul_dw2 = x[2]
drelu_dx0 = drelu_dxw0 * dmul_dx0	# chain rule
drelu_dw0 = drelu_dxw0 * dmul_dw0
drelu_dx1 = drelu_dxw1 * dmul_dx1
drelu_dw1 = drelu_dxw1 * dmul_dw1
drelu_dx2 = drelu_dxw2 * dmul_dx2
drelu_dw2 = drelu_dxw2 * dmul_dw2
#print(drelu_dx0, drelu_dw0, drelu_dx1, drelu_dw1, drelu_dx2, drelu_dw2)


# Optimized and w more neurons
import numpy as np

# Passed-in gradient from the next layer
dvalues = np.array([[1., 1., 1.]])

# 3 sets of weights - one set for each neuron
# 4 inputs, thus 4 weights
# Transpose so that weights * input matrix will have consistent dimensions
#	in this case, weights will need to be 4 x 3, because inputs are 3 x 1
#	and first matrix cols must equal second matrix rows
weights = np.array([[0.2, 0.8, -0.5, 1],
		    [0.5, -0.91, 0.26, -0.5],
		    [-0.26, -0.27, 0.17, 0.87]]).T

# Sum weights related to the given input multiplied by
# the gradient related to the given neuron
dx0 = sum([weights[0][0]*dvalues[0][0], weights[0][1]*dvalues[0][1],
	   weights[0][2]*dvalues[0][2]])
dx1 = sum([weights[1][0]*dvalues[0][0], weights[1][1]*dvalues[0][1],
	   weights[1][2]*dvalues[0][2]])
dx2 = sum([weights[2][0]*dvalues[0][0], weights[2][1]*dvalues[0][1],
	   weights[2][2]*dvalues[0][2]])
dx3 = sum([weights[3][0]*dvalues[0][0], weights[3][1]*dvalues[0][1],
	   weights[3][2]*dvalues[0][2]])

dinputs = np.array([dx0, dx1, dx2, dx3])
#print(dinputs)


# simplify the prev section
dx0 = sum(weights[0]*dvalues[0])
dx1 = sum(weights[1]*dvalues[0])
dx2 = sum(weights[2]*dvalues[0])
dx3 = sum(weights[3]*dvalues[0])

dinputs = np.array([dx0, dx1, dx2, dx3])
#print(dinputs)


# further simplified
dinputs = np.dot(dvalues[0], weights.T) # why transpose the weights twice?


# Using batches of samples
dvalues = np.array([[1., 1., 1.],
		   [2., 2., 2.],
		   [3., 3., 3.]])

dinputs = np.dot(dvalues, weights.T)
print(dinputs)


# Now with ReLU's partial derivative
dvalues = np.array([[1., 1., 1.],
		   [2., 2., 2.],
		   [3., 3., 3.]])

inputs = np.array([[1, 2, 3, 2.5],
		   [2., 5., -1., 2],
		   [-1.5, 2.7, 3.3, -0.8]])

weights = np.array([[0.2, 0.8, -0.5, 1],
		    [0.5, -0.91, 0.26, -0.5],
		    [-0.26, -0.27, 0.17, 0.87]]).T
# one bias per neuron
biases = np.array([[2, 3, 0.5]])

# Forward pass
layer_outputs = np.dot(inputs, weights) + biases	# Dense layer
relu_outputs = np.maximum(0, layer_outputs)		# ReLU activation

# Optimize and test backpropagation here
# Start w/ activation function of final layer
#	get its gradient
drelu = relu_outputs.copy()
drelu[layer_outputs <= 0] = 0

# Dense layer
# dinputs - multiply by weights (aka, their partial deriv)
dinputs = np.dot(drelu, weights.T)
# dweights - multiply by inputs (aka, their partial deriv)
dweights = np.dot(inputs.T, drelu)
# dbiases - sum values, do this over samples (first axis), keepdims
# since this by default will produce a plain list [don't remember this; review Chap 4]
dbiases = np.sum(drelu, axis=0, keepdims=True)

# Update parameters
learning_rate = -0.001
weights += learning_rate * dweights
biases += learning_rate * dbiases

print(weights)
print(biases)
