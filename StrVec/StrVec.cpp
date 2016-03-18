#include "StrVec.h"
#include <utility>
#include <iterator>
#include <iostream>
#include <algorithm>
#define VER_CPLUSPLUS 2011

using namespace std;

//start Implement for StrVec
StrVec::StrVec(const StrVec& orig)
{
	pair<string*,string*> p = alloc_n_copy(orig.elements, orig.size());
	elements = p.first;
	cap = first_free = p.second;
} 

StrVec& StrVec::operator=(const StrVec& sv)
{
	free();
	pair<string*,string*> p = alloc_n_copy(sv.elements, sv.size());
	elements = p.first;
	cap = first_free = p.second;
	return *this;
}

string& StrVec::operator[](size_t pos)
{
	if(pos >= size() || pos < 0)
		exit(1);
	return elements[pos];
}
StrVec::~StrVec()
{
	free();
}

bool StrVec::push_back(const string& s)
{
	if(!chk_n_alloc())
		return false;
	alloc.construct(first_free++, s);
}

void StrVec::pop_back()
{
	if(size() == 0)
		exit(1);
	alloc.destroy(--first_free);
}

bool StrVec::resize(size_t n, const string& s)
{
	if(n < size())
	{
		while(first_free-- != elements + n)
		{
			alloc.destroy(first_free);
		}
		return true;
	}
	else
	{
			reserve(n);
			if(capacity() >= n)
			{
				while(first_free != elements + n)
					alloc.construct(first_free++,s);
				return true;
			}
			return false;
	}
}

void StrVec::reserve(size_t n)
{
	if(n > capacity())
		reallocate_with_capacity(n);
}

void StrVec::shrink_to_fit()
{
	reallocate_with_capacity(size());
}

pair<string*,string*>
StrVec::alloc_n_copy(std::string *begin, size_t n)
{
	string *addr = alloc.allocate(n);
	return {addr,uninitialized_copy(begin, begin+n, addr)};
}

void StrVec::free()
{
	/*/
	while(first_free-- != elements)
		alloc.destroy(first_free);
	*/
    if(!elements)
    	return;
    
	for_each(elements,first_free,
		[this](string& s){alloc.destroy(&s);}); 
	alloc.deallocate(elements,capacity());
	
}

bool StrVec::chk_n_alloc()
{
	if(size() == capacity())	
		return reallocate();
	return true;
}
/*copy version*/

bool StrVec::reallocate()
{
	return reallocate_with_capacity(capacity()?capacity()*2:1);
}
bool StrVec::reallocate_with_capacity(size_t newCap)
{
	if(newCap < size())
	{
		cout<<"error! capacaity() will be less than size()"<<endl;
		return false;
	}
	string *newElements = alloc.allocate(newCap);
	if(!newElements)
		return false;
#if VER_CPLUSPLUS < 2011
	string *newFirst_free = uninitialized_copy(elements,first_free,newElements);
#else
	for(int i = 0; i != size(); ++i)
		alloc.construct(newElements+i,std::move(elements[i]));
	string *newFirst_free =newElements+size();
#endif
	free();
	elements = newElements;
	first_free = newFirst_free;
	cap = elements+newCap;
	return true;
}

allocator<string> StrVec::alloc = allocator<string>();
