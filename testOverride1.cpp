#include <iostream>
using namespace std;

class B
{
public:
	virtual void Func1(void)
	{
		cout<<"B's Func1 is called!"<<endl;
		Func2();
	}
	virtual void Func2(void)
	{
		cout<<"B's Func2 is called!"<<endl;
	}
};

class D : public B
{
public:
	virtual void Func1(void)
	{
		cout<<"D's Func1 is called!"<<endl;
		Func2();
	}
	virtual void Func2(void)
	{
		cout<<"D's Func2 is called!"<<endl;
	}	
};

int main()
{
	D d;
	D &dr = d;
	dr.B::Func1();
	
}
