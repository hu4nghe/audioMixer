#include "audioQueue.h"
#include <print>

class test
{
private :
	 inline static int count = 0;
public :
	 test()							{ count++;	std::print("default constructor | count :{}\n", count); }//default
	 test(const test& other)		{ count++;	std::print("copy	constructor | count :{}\n", count); }//copy constructor
	 test(test&& other) noexcept	{ count++;	std::print("move	constructor | count :{}\n", count); }//move constructor
	~test()							{ count--;	std::print("destructor          | count :{}\n", count); }
	static int getCount()			{ return count; }
};

int main()
{
	
	return 0;
}