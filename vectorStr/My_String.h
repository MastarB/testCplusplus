#ifndef _MY_STR_
#define _My_STR_ 52
#include <memory>

class My_String
{
public:
	typedef int size_t;
	My_String(const char * = "");
	My_String(const My_String& );
	My_String(My_String&& mys)noexcept;
	My_String& operator=(const My_String&);
	My_String& operator=(My_String&&)noexcept;
	size_t size()const{return _cap-_data;}
	size_t capacity()const{return _end_after-_data;}
	bool push_back(char c);
	void pop_back(); 
	~My_String();
	
private:
	static std::allocator<char> alloc; 
	char *_data;
	char *_end_after;
	char *_cap;
	void chk_n_size();
	void reallocate();
};

#endif
