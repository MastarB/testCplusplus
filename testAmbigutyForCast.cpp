#include <iostream>
using namespace std;

class LongDouble
{
public:
	LongDouble(double = 0.0){ }
	operator double()
	{ 
		cout<<"LongDouble->double cast is called"<<endl;
		return 0.0; 
	}
	operator float()
	{ 
		cout<<"LongDiybke->float cast is called"<<endl;
		return 0.0; 
	}
};

int main()
{
	LongDouble ld;
	float ex2 = ld;
	int ex1 = ld;
}
