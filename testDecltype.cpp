#include<iostream>
using namespace std;

int main()
{
	int a= 3, b = 4;
	decltype(a) c = a;
	decltype(a = b + 1)d = a;
	cout<<a<<b<<c<<d;//a3 b3 c4 d3
	//运行时也不会对括号内的表达式进行求值！！！！ 
}
