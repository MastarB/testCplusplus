#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		cout<<"default constructor is called"<<endl;
	}
	Test(const Test& orig)
	{
		cout<<"copy constructor is called"<<endl;	
	}
	
	Test& operator = (const Test &arig)
	{
		cout<<"operator: (copy assign) is called"<<endl;
	}
	
	
};

Test foo_bar(Test arg)
{
	Test local = arg, *heap = new Test(arg);
	*heap = local;
	Test pa [4] = {local, *heap};
	return *heap;
}

int main()
{
	Test a;
	foo_bar(a);
}


