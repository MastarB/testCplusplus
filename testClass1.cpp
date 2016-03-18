#include<iostream>
using namespace std;

class A
{
public:
	const int a = 1;
	A()
	{
		//a = 1;
	}
	/*
	A():a(2)
	{
		a = 2;
	}
	*/
};

int main()
{
	A a;
	cout<<a.a;
} 
