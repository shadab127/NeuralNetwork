# NeuralNetwork
ANN code in c++

Instructions for use:
include "Neuron.h","Layer.h" and "ANN.h"

## For creating ANN use following constructor:
> ANN ann(number of input, number of output, number of
           hidden layers, number of neurons per hidden layers,
           Alpha learning rate)

## For training ANN pass input and expected output vector in ANN.Go():
> vector<double> Go(vector<double> inputValues, vector<double> desiredOutput)

## For sample code run Brain.cpp which is configured for Xor operation.
