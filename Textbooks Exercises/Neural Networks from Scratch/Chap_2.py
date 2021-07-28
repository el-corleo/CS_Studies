# THE CASE OF A SINGLE NEURON
# ---------------------------
# Each neuron has inputs (init training data OR prev layer's outputs)
inputs = [1.2, 5.1, 2.1, 1.4]
# Each neuron has a unique weight for every input connection
weights = [3.1, 2.1, 8.7, 1.1]
# Each neuron has a unique bias
bias = 3

# Output is vector multiplication of weights and inputs plus the bias
# The result is a single scalar output
output = (inputs[0]*weights[0] + 
	  inputs[1]*weights[1] + 
	  inputs[2]*weights[2] +
	  inputs[3]*weights[3] + 
	  bias)

#print(output)


# ----------------------------
# THE CASE OF MULTIPLE NEURONS
# ----------------------------
# Each neuron shares the inputs (from the init training data OR the prev layer's outputs)
inputs = [1.2, 5.1, 2.1, 1.4]
# Each neuron has a unique set of weights (still one for each input)
weights = [[-3.1, 2.1, 8.7, 1.1],
	   [2.1, 3.1, -1.1, 8.7],
	   [0.1, -4.5, 3.9, 7.2],
	   [9.2, 3.1, 2.3, -1.9]]
# Each neuron has its own bias
biases = [2, 3, 5, 1]

# Outputs are likewise vector multiplications plus bias giving a scalar
outputs = [0, 0, 0, 0]
for i in range(len(weights)):
	for j in range(len(weights[i])):
		outputs[i] += inputs[j]*weights[i][j]
	outputs[i] += biases[i]


inputs = [1.2, 5.1, 2.1, 1.4]


#print(outputs)


# ----------------------------
# THE CASE OF MULTIPLE NEURONS (better-looking syntax)
# ----------------------------
#
inputs = [1, 2, 3, 2.5]
weights = [[0.2, 0.8, -0.5, 1],
	   [0.5, -0.91, 0.26, -0.5],
	   [-0.26, -0.27, 0.17, 0.87]]
biases = [2, 3, 0.5]

# Output of current layer
layer_outputs = []
# Modded for loop
# zip allows to iterate over multiple lists 
for neuron_weights, neuron_bias in zip(weights, biases):
	neuron_output = 0
	# weight each input and add to output
	for n_input, weight in zip(inputs, neuron_weights):
		neuron_output += n_input*weight
	# add in bias
	neuron_output += neuron_bias
	# add to output list
	layer_outputs.append(neuron_output)

#print(layer_outputs)


# When lists in list of lists are equal in len, they are "homologous"
# or in essence, 2D arrays are a "matrix"
# When you get into 3+ dimensions, they're called "tensors"
# The collective term for them is simply "array"

# The "shape" of an array is the list of its dimensions
# Vectors are 1 x X	(row, column)
# Matrices are X x Y	(row, column)
# Tensors are X x Y x Z, etc.

# Dot product
a = [1, 2, 3]
b = [4, 5, 6]

dot_product = a[0]*b[0] + a[1]*b[1] + a[2]*b[2]
#print(dot_product)

# Vector addition
vec_add = [a[0]+b[0], a[1]+b[1], a[2]+b[2]]
#print(vec_add)

import numpy as np

inputs = [1.0, 2.0, 3.0, 2.5]
weights = [0.2, 0.8, -0.5, 1.0]
bias = 2.0

# order of args doesn't seem to matter, at least in this case
outputs_1 = np.dot(weights, inputs) + bias
outputs_2 = np.dot(inputs, weights) + bias

#print(outputs_1)
#print(outputs_2)


# Layer of Neurons using numpy
inputs = [1.0, 2.0, 3.0, 2.5]
weights = [[0.2, 0.8, -0.5, 1.0],
	   [0.5, -0.91, 0.26, -0.5],
	   [-0.26, -0.27, 0.17, 0.87]]
biases = [2.0, 3.0, 0.5]

# order of args matters here
# counterintuitive as it may be, the A x B matrix order becomes np.dot(B, A) for some reason
#	nope! later on they switch so that it's inputs x weights.T, so A x B
layer_outputs_1 = np.dot(weights, inputs) + biases
#layer_outputs_2 = np.dot(inputs, weights) + biases

#print(layer_outputs_1)


# Matrix Product
# Basically matrix multiplication (?)
arr_1 = np.array([[1, 2, 3]])
tmp = [1, 2, 3]
arr_2 = np.array([tmp])

#print(arr_1)
#print(arr_2)

# To transpose, call .T on an np array
arr_3 = arr_1.T

#print(arr_3)

# mat mult using transposition
a = [1, 2, 3]
b = [2, 3, 4]

a = np.array([a])
b = np.array([b]).T

#print(np.dot(a, b))


# Layer of Neurons using a batch for training
input_batch = [[1.0, 2.0, 3.0, 2.5],
	       [2.0, 5.0, -1.0, 2.0],
	       [-1.5, 2.7, 3.3, -0.8]]
weights = [[0.2, 0.8, -0.5, 1.0],
	   [0.5, -0.91, 0.26, -0.5],
	   [-0.26, -0.27, 0.17, 0.87]]
biases = [2.0, 3.0, 0.5]

outputs = np.dot(input_batch, np.array(weights).T) + biases

#print(outputs)


# Complete code by end of Chap. 2
import numpy as np

inputs = [[1.0, 2.0, 3.0, 2.5],
	  [2.0, 5.0, -1.0, 2.0],
	  [-1.5, 2.7, 3.3, -0.8]]
weights = [[0.2, 0.8, -0.5, 1.0],
	   [0.5, -0.91, 0.26, -0.5],
	   [-0.26, -0.27, 0.17, 0.87]]
biases = [2.0, 3.0, 0.5]

layer_outputs = np.dot(inputs, np.array(weights).T) + biases

print(layer_outputs)
