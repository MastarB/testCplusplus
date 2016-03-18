#include <iostream>
using namespace std;

class Base
{
public:
	Base(int a, int b):amem(a),bmem(b) {}
private:
	int amem;
	int bmem;
		
};
class D;

void printC(const D& d);

class D : public Base
{	
	friend void printC(const D& d);
public:
	using Base::Base;
private:
	int cmem[10];
};

void printC(const D& d)
{
	for(int i : d.cmem)
		cout<<i<<' ';
}
int main()
{
	D d(4,2);
	printC(d);
	
} 
