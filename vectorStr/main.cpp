#include <iostream>
#include "My_String.h"
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	vector<My_String>strVec1;
	for(int i = 0; i < 20; ++i)
		strVec1.push_back(My_String("11"));
	
	return 0;
}
