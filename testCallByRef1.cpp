#include<iostream>
#include<string>
using namespace std;

/*
bool is_empty1(string& a)*/
bool is_empty(const string& a)
{
	return a.empty();
}

int main()
{
	cout<<(is_empty1("")?"true":"false");
}
