#ifndef _TEXT_QUERY_
#define _TEXT_QUERY_ 1

#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <memory>

class QueryResult;

std::ostream &operator << (std::ostream & , const QueryResult &);

class QueryResult
{
	friend std::ostream &operator <<(std::ostream &out, const QueryResult &result);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<int>> setP, std::shared_ptr<std::vector<std::string>> vecP):
		queryStr(s),lines(setP),file(vecP)
		{
			
		}
	
	std::ostream &resultPrint(std::ostream &out)const
	{
		out<<*this;
	}
	
private:
	std::string queryStr;
	std::shared_ptr<std::set<int>> lines;
	std::shared_ptr<std::vector<std::string>>file;
	
};

std::ostream &operator <<(std::ostream &out, const QueryResult &result)
{
		if(result.lines)
		{
			out<<"the word "<<result.queryStr<<" occurs in "<<
				result.lines->size()<<" lines :"<<std::endl;
			for(int i : *result.lines)
				out<<"(line "<<i+1<<")"<<result.file->at(i)<<std::endl;
		}
		else
			out<<"the word "<<result.queryStr<<" not found !"<<std::endl;
		return out;
}

class TextHandler
{
public:
	TextHandler(std::istream& in):lines(new std::vector<std::string>()),
		word_line_map()
	{
		
		std::string tmp;
		while(std::getline(in,tmp))
			lines->push_back(tmp);
		
		
		for(int i = 0; i < lines->size(); ++i)
		{
			
			std::istringstream iss(lines->at(i));
			std::string word;

			while(iss>>word)
			{
				if(word_line_map.find(word) == word_line_map.end())
					word_line_map[word].reset(new std::set<int>);
				word_line_map[word]->insert(i);
			}
		}	
	}
	
	QueryResult query(const std::string &s)const
	{
		//std::cout<<"stored1"<<std::endl;
		return word_line_map.find(s) == word_line_map.end()?
			QueryResult(s,std::shared_ptr<std::set<int>>(),lines):
			QueryResult(s,word_line_map.find(s)->second,lines);
	}

private:
	std::shared_ptr<std::vector<std::string>>lines;
	std::map<std::string,std::shared_ptr<std::set<int>>>word_line_map;
};

#endif
