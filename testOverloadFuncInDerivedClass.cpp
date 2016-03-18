#include <iostream>
using namespace std;

class Base
{
public:
	virtual int fcn(){return 1;}	
	virtual int fcn(int i){return i;}
};
class D1 : public Base
{
public:
	//using Base::fcn; this is neccessary !!
	int fcn(int i){return i;}
};

class D2 :public D1
{
public:
	int fcn(){return 3;} 
};

int main()
{
	D1 d1obj;
	D2 d2obj;
	D1 *d2p = &d2obj;

	cout<<d2p->fcn();//error  no matching function for call to D!::fcn() !
}
