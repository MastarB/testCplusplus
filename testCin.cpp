#include <iostream>
#include <functional> 
#include <algorithm>
#include <iterator>

using namespace std;

bool func1(double d1,double d2)
{
	cout<<"double ver is called."<<endl;
	return d1-d2 > 0;
}

bool func1(int i1, int i2, double d3)
{
	cout<<"int ver is called."<<endl;
	return i1-i2 > 0;
}
int main()
{
	int t = 3;
	vector<int>v1 = {1,3,4,5,7,9};
	vector<int>v2;
	using namespace placeholders;
	copy_if(v1.begin(),v1.end(),back_inserter(v2),bind(func1,_1,t,t));
	
}
