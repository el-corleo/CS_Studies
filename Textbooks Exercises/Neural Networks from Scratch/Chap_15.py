import numpy as np

# Dropout
class Layer_Dropout:
    
    def __init__(self, rate):
        # Param rate indicates what percent to drop
        # Member rate indicates what percent to keep
        self.rate = 1 - rate
    
    def forward(self, inputs):
        self.inputs = inputs
        self.binary_mask = np.random.binomial(1, self.rate, size=inputs.shape) / self.rate
        self.outputs = inputs * self.binary_mask
        
    def backward(self, dvals):
        self.dinputs = dvals * self.binary_mask

...
        
layer_1 = Layer_Dense(...)
act_func_1 = Activation_ReLU()
dropout_1 = Layer_Dropout(0.1)
layer_2 = Layer_Dense(...)

...

dropout_1.forward(act_func_1)
layer_2.forward(dropout_1)

...

dropout_1.backward(layer_2.dinputs)
act_func_1.backward(dropout_1)
