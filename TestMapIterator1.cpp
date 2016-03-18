#include<map>
#include<list>
#include<utility>
#include<iostream>
using namespace std;
/*struct myCom
{
	bool operator > (const pair<int,int>& p1, const pair<int,int>& p2)
	{
		return p1.first > p2.first || p1.first == p2.first&&p1.second > p2.second;  
	}
	
	bool operator ()(const pair<int,int>& p1, const pair<int,int>& p2)
	{
		return p1.first == p2.first&&p1.second == p2.second;
	}
};*/

int main()
{
	//method 'push_back' in 'vector'will destory the iterator u have reversed for the former elements !!
	//However, method 'push_back' in 'list' won't !
	list<int>que;
	map<int,list<int>::iterator>m;
	que.insert(que.end(),2);
	m[2] = --que.end();
	que.insert(que.end(),3);
	m[3] = --que.end();
	cout<<*m[2];
}
