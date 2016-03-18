#include <memory> 
#include <iostream>
using namespace std;

int main()
{
	allocator<string>allo;
	auto const n = 10;
	auto const p = allo.allocate(n);
	string s;
	
	auto q = p;
	while(cin>>s && q != p+n)
		allo.construct(q++,s+'s');
		// s can also be replaced by the args of the other initializer of class string !
	
	for(auto i = p; i != q; ++i)
		cout<<*i<<endl;
		
	while(q != p)
		allo.destroy(--q);
	allo.deallocate(p,n);
	
}
