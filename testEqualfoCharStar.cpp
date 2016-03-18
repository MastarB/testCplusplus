#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	if("string" == strdup("string"))
		cout<<"compare val of string not address!";
} 
