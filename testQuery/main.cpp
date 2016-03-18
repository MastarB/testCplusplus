#include "TextQuery.h"
#include <iostream>
#include <fstream>
 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	if(argc == 2)
	{
		cout<<"loading the text file: "<<argv[1]<<endl;
		ifstream fileIn(argv[1]);
		cout<<"loading completed."<<endl;
		cout<<"analyzing the text."<<endl;
		TextHandler handler(fileIn);
		cout<<"analyzing completed."<<endl;
		do
		{
			cout<<"Please enter the word you want to query (enter #Q to exit)"<<endl;
			string enter;
			cin>>enter;
			if(enter == "#Q")
				break;
			cout<<handler.query(enter);
		}while(true);
	}
	return 0;
}
