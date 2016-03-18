class A
{
	/*const*/ A& get()
	{
		return *this;
	}
	
	const A& get()const
	{
		return *this;
	}
};
