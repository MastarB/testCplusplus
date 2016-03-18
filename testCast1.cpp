#include<iostream>
using namespace std;

int main()
{
	//cout<<sizeof(unsigned long long);
	unsigned long long a = 1;
	void *b = reinterpret_cast<void*>(a);
	void *c = 
	//static_case is erro
	//void *b = static_cast<void*>(a);
	cout<<b;
	
}
