/**
 * @Author: shadabKhan
 * @Date:   Friday, April 10th 2020, 10:45:16 am
 * @Last modified by:   shadabKhan
 * @Last modified time: Monday, April 13th 2020, 9:29:29 am
 */

 #include <iostream>
 #include <vector>
 #include <ctime>
 #include <random>
 #include <cstdlib>
using namespace std;
class Neuron{
public:
  	 int numInputs;
  	 double bias;
  	 double output;
  	 double errorGradient;
  	 vector<double> weights =  vector<double>();
  	 vector<double> inputs =  vector<double>();

     Neuron(int nInputs)
   	{
   		bias =RandomRange(-1.0f,1.0f);
   		numInputs = nInputs;
   		for(int i = 0; i < nInputs; i++)
   			weights.push_back(RandomRange(-1.0f,1.0f));
   	}
    float RandomRange(float LO,float HI)
    {
      static std::default_random_engine e;
      static std::uniform_real_distribution<> dis(LO, HI); // rage 0 - 1
      float random_no = dis(e);
      //cout<<random_no<<endl;
      return random_no;
    }
    /*float RandomRange(float LO,float HI)
    {
      srand(time(0));
      float r3 = LO + (rand()) /( (RAND_MAX/(HI-LO)));
    // cout<<r3<<endl;
      return r3;
    }*/
};
