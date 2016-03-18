#include<iostream>
using namespace std;

int PowWith2(int i)
{
    	int c = 1;
    	int mul = 2;
    	while(i != 0)
    	{
    		if(i%2 == 1)
    			c *= mul;
    		mul *= mul;
    		i /= 2;	 
		}
		return c;
}

int main()
{
	for(int i = 0; i < 10; i++)
		cout<<PowWith2(i);
}
