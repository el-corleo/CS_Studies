import math

# An example output from the output layer of the NN [y-hat]
softmax_output = [0.7, 0.1, 0.2]
# Ground truth (i.e., actual values [y])
target_output = [1, 0, 0]

loss = 0

# categorical cross-entropy loss
# not necessary to multiply by ground truth [y]
#	if y is one-hot
for y_hat, y in zip(softmax_output, target_output):
	loss += y*math.log(y_hat)

loss *= -1

#print(loss)


import numpy as np

# Simplified version
softmax_outputs = np.array([[0.7, 0.1, 0.2],
			    [0.1, 0.5, 0.4],
			    [0.02, 0.9, 0.08]])
class_targets = np.array([[1, 0, 0],
			  [0, 1, 0],
			  [0, 1, 0]])

neg_log = -np.log(softmax_outputs[range(len(softmax_outputs)), class_targets])
avg_loss = np.mean(neg_log)

#print(avg_loss)


# clipping to avoid division by zero for ln(0) for zeros in the
# one-hot encoder's vector
y_pred_clipped = np.clip(softmax_outputs, 1e-7, 1 - 1e-7)



# Loss class
class Loss:
	
	# calculates the data and regularization losses
	# given model output (y-hat) and ground truth (y) values
	def calculate(self, y_hat, y):
		sample_losses = self.forward(y_hat, y)
		mean_loss = np.mean(sample_losses)
		return mean_loss


# Categorical cross-entropy loss class
class Loss_CategoricalCrossEntropy(Loss):

	# forward pass
	def forward(self, y_hat, y):
		samples = len(y_hat)
		# clip data to prevent div by 0
		# clip both sides to avoid shifting mean toward either value
		y_hat_clipped = np.clip(y_hat, 1e-7, 1 - 1e-7)

		# probabilities for target values for categorical labels
		if len(y.shape) == 1:
			correct_confidences = y_hat_clipped[range(samples), y]
		# mask values for one-hot encoded labels
		elif len(y.shape) == 2:
			correct_confidences = np.sum(y_hat_clipped*y, axis=1)

		# losses
		neg_log_likelihoods = -np.log(correct_confidences)
		return neg_log_likelihoods


loss_function = Loss_CategoricalCrossEntropy()
loss = loss_function.calculate(softmax_outputs, class_targets)
print(loss)	
