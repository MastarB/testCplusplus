#include <string>
#include <iostream>
using namespace std;

class string
{
		
};
int main()
{	
	//string is not in this scope, so compiler search outside of main() and find two string class
	using std::string;// or using ::string;
	string a;// error!

}

