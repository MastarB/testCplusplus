#include<map>
#include<list>
#include<utility>
#include<iostream>
using namespace std;
struct myCom
{
	bool operator > (const pair<int,int>& p1, const pair<int,int>& p2)
	{
		return p1.first > p2.first || p1.first == p2.first&&p1.second > p2.second;  
	}
	
	bool operator ()(const pair<int,int>& p1, const pair<int,int>& p2)
	{
		return p1.first == p2.first&&p1.second == p2.second;
	}
};
int main()
{
	list<int>que;
	map<pair<int,int>,list<int>::iterator,myCom>m;
	que.push_back(2);
	m[make_pair(1,2)] = --que.end();
	que.push_back(3);
	m[make_pair(2,3)] = --que.end();
	cout<<*m[make_pair(1,2)];
}
