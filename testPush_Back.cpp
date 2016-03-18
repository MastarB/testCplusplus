#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	vector<string>vecs;
	string a("a");
	vecs.push_back(a);
	a = "b";
	vecs.push_back(a);
	cout<<vecs[0]<<vecs[1];
} 
