#include<iostream>
using namespace std;

struct STR11
{
	int a,b;
	STR11():a(2),b(3){}
};
struct STR1
{
	STR11 str;
	int b;
	STR1():b(1){}
};



int main()
{
	STR1* str1 = new STR1();
	STR11* str2 = reinterpret_cast<STR11*>(str1);
	cout<<&(str1->str)<<endl;
	cout<<str2<<endl;
	cout<<&(str2->a)<<endl<<&(str2->b)<<endl;
	cout<<sizeof(STR1);
}
