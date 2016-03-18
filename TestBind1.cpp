#include<functional>
#include<iostream>
using namespace std;
#define CC_CALLBACK_1(__selector__,__target__, ...) std::bind(&__selector__,__target__, std::placeholders::_1, ##__VA_ARGS__)

class FC
{
public:
	void fc(int* a)
	{
		cout<<a;
	}
	
	
};
int main()
{
	FC t;
	int a = 1;
	auto fcB = CC_CALLBACK_1(FC::fc,&t);
	fcB(&a);s
} 
