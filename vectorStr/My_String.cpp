#include "My_String.h"
#include <memory>
#include <cstring>
#include <iostream>

using namespace std;

My_String::My_String(const char *str)
{
	size_t len = strlen(str);
	char *address = alloc.allocate(len+1);
	strcpy(address, str);
	_data = address;
	_cap = _data+len+1;
	_end_after = _data+len;
	cout<<(!strcmp(str,"")?"default constructor is called":"constructor 1 is called");
	cout<<endl;
}

My_String::My_String(const My_String& mys)
{
	size_t len = strlen(mys._data);
	char *address = alloc.allocate(len+1);
	strcpy(address, mys._data);
	_data = address;
	_cap = _data+len+1;
	_end_after = _data+len;
	cout<<"copy constructor is called!"<<endl;
}

My_String::My_String(My_String&& mys) noexcept
{
	_data = mys._data; 
	_cap = mys._cap;
	_end_after = mys._end_after;
	mys._data = mys._cap = 0;
	cout<<"move constructor is called"<<endl;
}

My_String& My_String::operator=(const My_String& mys)
{
	if(mys.size()+1 > capacity())
	{
		alloc.deallocate(_data,capacity());
		_data = alloc.allocate(mys.size()+1);
	}
	strcpy(_data,mys._data);
	_end_after = _data+mys.size();
	_cap = _data+mys.size()+1;
	return *this;
}

My_String& My_String::operator=(My_String&& mys)noexcept
{
	alloc.deallocate(_data,capacity());
	_data = mys._data; 
	_cap = mys._cap;
	_end_after = mys._end_after;
	mys._data = mys._cap = 0;
	return *this;
}
 
My_String::~My_String()
{
	alloc.deallocate(_data,capacity());
}

bool My_String::push_back(char c)
{
	chk_n_size();
	if(size() >= capacity()+1)
		return false;
	*_end_after++ = c;
	*_end_after = '\0';
	return true; 
}

void My_String::pop_back()
{
	if(size() == 0)
		exit(1);
	*--_end_after = '\0';
}

void My_String::chk_n_size()
{
	if(size() == capacity() - 1)
		reallocate();	
} 

void My_String::reallocate()
{
	size_t newCap = 2*capacity();
	char *newData = alloc.allocate(newCap);
	strcpy(newData, _data);
	alloc.deallocate(_data, capacity());
	_data = newData;
	size_t len = strlen(_data);
	_end_after = newData + len;
	_cap = newData + newCap;
}

allocator<char> My_String::alloc = allocator<char>();
