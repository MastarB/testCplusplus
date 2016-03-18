#ifndef _STRING_VECTOR_
#define _STRING_VECTOR_ 1

#include <string>
#include <memory>

class StrVec;

void swap(StrVec& v1, StrVec& v2);

class StrVec
{
	friend void swap(StrVec& v1, StrVec& v2);
public:
	typedef int size_t;
	StrVec():
		elements(nullptr),first_free(nullptr),cap(nullptr)
		{}
	StrVec(const StrVec& sv);
	StrVec& operator=(const StrVec& sv);
	std::string& operator[](size_t pos);
	~StrVec();
	bool push_back(const std::string& s);
	void pop_back();
	bool resize(size_t n, const std::string& s = "");
	void reserve(size_t n);
	void shrink_to_fit();
	std::string *begin(){return elements;}
	std::string *end(){return first_free;}
	size_t size()const{return first_free-elements;}
	size_t capacity()const{return cap-elements;}
	 
private:

	std::string *elements;
	std::string *first_free;
	std::string *cap;
	static std::allocator<std::string> alloc;
	
	std::pair<std::string*,std::string*> alloc_n_copy(std::string *begin, size_t n);
	void free();
	bool chk_n_alloc();
	bool reallocate();
	bool reallocate_with_capacity(size_t newCap);
	
};

#endif
