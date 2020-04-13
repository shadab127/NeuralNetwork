/**
 * @Author: shadabKhan
 * @Date:   Saturday, April 11th 2020, 11:03:17 pm
 * @Last modified by:   shadabKhan
 * @Last modified time: Monday, April 13th 2020, 9:33:43 am
 */
#include<iostream>
#include<vector>
#include<math.h>
#include"ANN.h"
using namespace std;

vector<double> Train(ANN &ann,double i1, double i2, double o)
{
  vector<double> inputs;
  vector<double> outputs;
  inputs.push_back(i1);
  inputs.push_back(i2);
  outputs.push_back(o);
  return (ann.Go(inputs,outputs));
}

int main()
{
	double sumSquareError = 0;

  ANN ann(2, 1, 1, 2, 0.8);
  // ANN ann(number of input, number of output, number of
  //          hidden layers, number of neurons per hidden layers,
  //          Alpha learning rate)
		vector<double> result;

		for(int i = 0; i < 100000; i++)
		{
			sumSquareError = 0;
			result = Train(ann,1, 1, 0);
			sumSquareError += pow((float)result[0] - 0,2);
			result = Train(ann,1, 0, 1);
			sumSquareError += pow((float)result[0] - 1,2);
			result = Train(ann,0, 1, 1);
			sumSquareError += pow((float)result[0] - 1,2);
			result = Train(ann,0, 0, 0);
			sumSquareError += pow((float)result[0] - 0,2);
		}
    cout<<"SSE: " << sumSquareError<<endl;
		result = Train(ann,1, 1, 0);
		cout<<" 1 1 " << result[0]<<endl;
		result = Train(ann,1, 0, 1);
		cout<<" 1 0 "<< result[0]<<endl;
		result = Train(ann,0, 1, 1);
		cout<<" 0 1 "<< result[0]<<endl;
		result = Train(ann,0, 0, 0);
		cout<<" 0 0 " <<result[0]<<endl;
}
