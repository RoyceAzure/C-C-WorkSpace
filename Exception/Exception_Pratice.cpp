#include<iostream>
#include<stdlib.h>
#include <string.h>
#include <exception>
using namespace std;

class Myexceptin: exception
{
	
};


void mightGoWrong()
{
	bool error1 = true;
	bool error2 = false;
	
	
	if(error1)
	{
		throw bad_alloc();
	}
	if(error2)
	{
		throw exception();
	}
}

int main()
{
	try
	{
		mightGoWrong();		
	}	
	catch(exception &e)
	{
		cout << e.what() << endl;
	}
	catch(bad_alloc &e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
