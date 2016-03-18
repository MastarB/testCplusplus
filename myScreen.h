#include<string>
class Screen
{
public:
	typedef unsigned int pos;
	Screen(): width(0),height(0),cur(0), field("") { }
	Screen(pos width = 80, pos height = 24, char c = ' '):
	width(width),height(height),cur(0),field(width*height,c) { }
	
	char get()const
	{
		return field[cur];
	}
	
	char get(pos row, pos col)const 
	{	
		return field[row*width + col];
	}
	
	bool isCharacter(char c)
	{
		return true;
	}
	
	pos getHeight()const
	{
		return height;
	}
	
	pos getWidth()const
	{
		return width;
	}
	
	inline Screen& move(pos row, pos col);
	
	inline Screen& set(char c);

	inline Screen& type(char c);

	
	
private:
	pos width;
	pos height;
	pos cur;
	std::string field;
};
