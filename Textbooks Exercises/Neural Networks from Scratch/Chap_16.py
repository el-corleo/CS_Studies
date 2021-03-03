import numpy as np

# Sigmoid Activation
# Useful for binary classifications as it compresses inputs into range (0,1)
class Activation_Sigmoid:

    def forward(self, inputs):
        self.inputs = inputs
        # sigmoid function is
        # 1 / (1 + e^-x)
        self.outputs = 1 / (1 + np.exp(-inputs))

    def backward(self, dvals):
        # derivative of sigmoid function is
        # sigmoid * (1 - sigmoid)
        self.dinputs = dvals * (1 - self.outputs) * self.outputs

# Binary Cross-Entropy Loss
class Loss_BinaryCrossEntropy(Loss):

    def forward(self, y_hat, y):
        y_hat_clipped = np.clip(y_hat, 1e-7, 1 - 1e-7)
        
        sample_losses = -(y * np.log(y_hat_clipped) + (1 - y) * np.log(1 - y_hat_clipped))
        sample_losses = np.mean(sample_losses, axis=-1)

        return sample_losses

    def backward(self, dvals, y):
        n_samples = len(dvals)
        outputs = len(dvals[0])
        clipped_dvals = np.clip(dvals, 1e-7, 1 - 1e-7)

        self.dinputs = -(y / clipped_dvals - (1 / y) / (1 - clipped_dvals)) / outputs

        self.dinputs = self.dinputs / n_samples


# --------------
# Usage

X, y = spiral_data(samples=100, classes=2)
y = y.reshape(-1, 1)

# ...

final_layer_activation = Activation_Sigmoid()
loss_func = Loss_BinaryCrossEntropy()

predictions = (final_layer_activation.outputs > 0.5) * 1
accuracy = np.mean(predictions==y_test)


