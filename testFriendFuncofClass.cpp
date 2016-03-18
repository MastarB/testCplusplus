class B;
class A
{
public:
	int a = 1;
	funcA()
	{
		
	}
	//friend B::funcB();
};

class B
{
public:
	int b = 2;
	funcB()
	{
		
	}
	friend A::funcA();
};

friend A::B::funcB; 

