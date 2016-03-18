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
		cout<<"LongDouble->float cast is called"<<endl;
		return 0.0; 
	}
};

void calc(int)
{
	cout<<"int_calc is called"<<endl;
}

void calc(LongDouble)
{
	cout<<"LongDouble_calc is called"<<endl;
}

int main()
{
	double val;
	calc(val);
}


