/**
 * @Author: shadabKhan
 * @Date:   Friday, April 10th 2020, 2:17:23 pm
 * @Last modified by:   shadabKhan
 * @Last modified time: Sunday, April 12th 2020, 3:28:54 pm
 */

 #include <iostream>
 #include <vector>
#include "Neuron.h"
using namespace std;

class Layer {
public:
	 int numNeurons;
	 vector<Neuron> neurons =  vector<Neuron>();

	 Layer(int nNeurons, int numNeuronInputs)
	{
		numNeurons = nNeurons;
		for(int i = 0; i < nNeurons; i++)
		{
			neurons.push_back( Neuron(numNeuronInputs));
		}
	}
};
