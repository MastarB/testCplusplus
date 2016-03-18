#include <set>
#include <iterator>
#include <iostream>
#include <map>

using namespace std;
int main()
{
	
	map<int,int>m = {{1,1},{2,3},{5,8}};
	auto i = m.find(2);
	i->second = 4;
	auto j = m.find(2);
	cout<<j->second;

/*	vector<string>vec;
	for(int i = 0; i < 10; ++i)
	{
		
	}
	
	set<string>set1;
	set1.insert()
	auto inst = inserter(set1,set1.begin());*/
}
