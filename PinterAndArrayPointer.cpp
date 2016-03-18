#include <iostream>
using namespace std;

void func1(int *a)
{
	cout<<"PointerVer is called!"<<endl;
}

void func1(int (*a)[10])
{
	cout<<"arrayPointerVer is called!"<<endl;
}
int main()
{
	int a[10];
	cout<<a<<' '<<&a;
	//func1(&a);
 } 
