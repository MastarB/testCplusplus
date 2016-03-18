#include <iostream>
using namespace std;
class Quote
{
public:
	typedef int size_t;
	virtual	size_t net_Prize(size_t count)
	{
		cout<<"Quote::net_Prize is called!"<<endl;
		return prize * count;
	}
protected:
	size_t prize = 0.0;
};

class Disc_quote : public Quote
{
public:
	typedef double rate;
	size_t net_Prize(size_t count) = 0;
protected:
	rate discount = 0.8;
};

class Bulk_quote : public Disc_quote
{
public:
	virtual size_t net_Prize(size_t count)
	{
		cout<<"Bulk_quote is called!"<<endl;
		if(count <= 10)
			return prize * count *discount;
		else
			return prize * 10 * discount + (count - 10) * prize;
	}
private:
	size_t upperbound = 10;
};

int main()
{
	Bulk_quote bq;
	Quote &bqr = bq;
	bqr.net_Prize(2);
}
