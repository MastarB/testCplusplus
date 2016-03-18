#include <iostream>
#include "StrVec.h"
#include <cstdlib>
#include <ctime>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void printSizeAndCap(const StrVec& v)
{
	cout<<"size: "<<v.size()<<", capacity: "<<v.capacity()<<endl;
}
string strGenerator()
{ 
	int len = rand()%10+1;
	string builder("");
	for(int i = 0; i < len; ++i)
		builder.push_back('a'+rand()%26);
	return builder;
		
}

int main(int argc, char** argv) 
{
	srand(time(0));
	StrVec v1;
	for(int i = 0; i < 10; ++i)
	{
		string s = strGenerator();
		cout<<s<<"'."<<endl;
		v1.push_back(s);
		printSizeAndCap(v1);
	}
	v1.pop_back();
	printSizeAndCap(v1);
	StrVec v2(v1);
	printSizeAndCap(v2);
	v2.reserve(20);
	printSizeAndCap(v2);
	v2.resize(20);
	printSizeAndCap(v2);
	return 0;
}

