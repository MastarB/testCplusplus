#include<iostream>
#include<functional>
using namespace std;

class Fuck
{
public:
	void out(int a)
	{
		cout<<this<<' '<<a<<endl;
	}
};

int main()
{
	Fuck a;
	a.out(1);
	function<void(Fuck,int)> outInFuck = Fuck::out;
	outInFuck(a,2);
}
