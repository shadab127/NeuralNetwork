/**
 * @Author: shadabKhan
 * @Date:   Friday, April 10th 2020, 2:21:02 pm
 * @Last modified by:   shadabKhan
 * @Last modified time: Sunday, April 12th 2020, 2:50:08 pm
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include"Layer.h"
using namespace std;
class ANN{
public:
  int numInputs;
	int numOutputs;
	int numHidden;
	int numNPerHidden;
	double alpha;
	vector<Layer> layers =  vector<Layer>();

	ANN(int nI, int nO, int nH, int nPH, double a)
	{
		numInputs = nI;
		numOutputs = nO;
		numHidden = nH;
		numNPerHidden = nPH;
		alpha = a;

		if(numHidden > 0)
		{
			layers.push_back( Layer(numNPerHidden, numInputs));

			for(int i = 0; i < numHidden-1; i++)
			{
				layers.push_back( Layer(numNPerHidden, numNPerHidden));
			}

			layers.push_back( Layer(numOutputs, numNPerHidden));
		}
		else
		{
			layers.push_back( Layer(numOutputs, numInputs));
		}
	}

	 vector<double> Go(vector<double> inputValues, vector<double> desiredOutput)
	{
		vector<double> inputs =  vector<double>();
		vector<double> outputs =  vector<double>();

		if(inputValues.size() != numInputs)
		{
			cout<<"ERROR: Number of Inputs must be " << numInputs<<endl;
			return outputs;
		}

		inputs =  vector<double>(inputValues);
		for(int i = 0; i < numHidden + 1; i++)
		{
				if(i > 0)
				{
					inputs =  vector<double>(outputs);
				}
				outputs.clear();

				for(int j = 0; j < layers[i].numNeurons; j++)
				{
					double N = 0;
					layers[i].neurons[j].inputs.clear();

					for(int k = 0; k < layers[i].neurons[j].numInputs; k++)
					{
					    layers[i].neurons[j].inputs.push_back(inputs[k]);
						N += layers[i].neurons[j].weights[k] * inputs[k];
					}

					N -= layers[i].neurons[j].bias;
					layers[i].neurons[j].output = ActivationFunction(N);
					outputs.push_back(layers[i].neurons[j].output);
				}
		}

		UpdateWeights(outputs, desiredOutput);

		return outputs;
	}

	void UpdateWeights(vector<double> outputs, vector<double> desiredOutput)
	{
		double error;
		for(int i = numHidden; i >= 0; i--)
		{
			for(int j = 0; j < layers[i].numNeurons; j++)
			{
				if(i == numHidden)
				{
					error = desiredOutput[j] - outputs[j];
					layers[i].neurons[j].errorGradient = outputs[j] * (1-outputs[j]) * error;
					//errorGradient calculated with Delta Rule: en.wikipedia.org/wiki/Delta_rule
				}
				else
				{
					layers[i].neurons[j].errorGradient = layers[i].neurons[j].output * (1-layers[i].neurons[j].output);
					double errorGradSum = 0;
					for(int p = 0; p < layers[i+1].numNeurons; p++)
					{
						errorGradSum += layers[i+1].neurons[p].errorGradient * layers[i+1].neurons[p].weights[j];
					}
					layers[i].neurons[j].errorGradient *= errorGradSum;
				}
				for(int k = 0; k < layers[i].neurons[j].numInputs; k++)
				{
					if(i == numHidden)
					{
						error = desiredOutput[j] - outputs[j];
						layers[i].neurons[j].weights[k] += alpha * layers[i].neurons[j].inputs[k] * error;
					}
					else
					{
						layers[i].neurons[j].weights[k] += alpha * layers[i].neurons[j].inputs[k] * layers[i].neurons[j].errorGradient;
					}
				}
				layers[i].neurons[j].bias += alpha * -1 * layers[i].neurons[j].errorGradient;
			}

		}

	}

	//for full vector of activation functions
	//see en.wikipedia.org/wiki/Activation_function
	double ActivationFunction(double value)
	{
		return Sigmoid(value);
	}

	double Step(double value) //(aka binary step)
	{
		if(value < 0) return 0;
		else return 1;
	}

		double Relu(double value) //(aka binary step)
		{
			if(value > 0) return value;
			else return 0;
		}
		double LRelu(double value) //(aka binary step)
		{
			if(value > 0) return value;
			else return 0.01*value;
		}
	double Sigmoid(double value) //(aka logistic softstep)
	{
    	double k =  exp(value);
    	return k / (1.0f + k);
	}
	double Sinusoid(double value)
{
	return sin((float) value);
}

double ArcTan(double value)
{
	return tanh((float) value);
}

double SoftSign(double value)
{
	return value/(1+abs((float)value));
}
};
