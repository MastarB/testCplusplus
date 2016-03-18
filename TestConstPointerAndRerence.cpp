#include<vector>
using namespace std; 
int main()
{
	int i, *const cp = &i; // const pointers must be initailized when they are defined !
//	int *p1, *const p2;
//	const int ic, &r = ic;
//	const int *const p3;
	const int *p = &i;
	vector<int>aa;
	
	aa.erase(aa.end());
}
