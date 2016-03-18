#include <iostream>
using namespace std;

void swap(int a, int b, int c)
{
	cout<<"::swap(int, int, int) is called"<<endl;
}

void swap(double d1, double d2)
{
	cout<<"::swap(double, double) is called"<<endl;
}
	
void swap(int a, int b)
{
	cout<<"::swap(int, int) is called"<<endl;
}

class Test
{
public:
	
	void swap(int a, int b)
	{
		cout<<"Test::swap(int,int) is called"<<endl;
	}
	void test()
	{
		using std::swap;
		using Test::swap;
		swap(1,1);
	}	
};

int main()
{
	Test t;
	t.test();
}
