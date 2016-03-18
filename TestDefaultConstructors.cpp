#include<iostream>
using namespace std;

class B
{
public:
	B()
	{
		cout<<"B is created"<<endl;
	}
};

class Fa 
{
public:
	Fa()
	{
		cout<<"Fa's default constr is called"<<std::endl;
	}
};


class Son : public Fa 
{
public:
	B b;
	Son(int a)
	{
		cout<<"son's constr(a) is called"<<endl;	
	}
	
	Son(double b)
	{
		
	}
	
};

int main()
{
	Son so(1);
}
