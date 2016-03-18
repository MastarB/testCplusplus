#include<vector>
#include<string>
using namespace std;
class B
{
public:
	int a;
	double b;	
};
class A
{
public:
	
	static const int i = 1;
	static const double d = i;//error
	//static constexpr double d = 1;
	static constexpr B b = {1,0.0}; //right
	vector<int>v;
}; 

//vector<int>A::vec(1);
