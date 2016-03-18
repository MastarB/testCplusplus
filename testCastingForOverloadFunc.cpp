#include <iostream>
using namespace std;
class Test
{
public:
	Test(int i = 0)
	{
		
	}
	operator int()const{return 1;}
		
};
void func(const Test& t)
{
	
}
int main()
{
	func(3.0);
}
