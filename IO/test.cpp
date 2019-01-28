#include <iostream>
#include <string>
#include <fstream>


using namespace std;


int main()
{
	const char *filename = "test.txt";
	
	ifstream input;
	
	input.open(filename);
	if(!input.is_open())
	{
		cout<<"open failed!"<<endl;
		return 1;
	}
	
//	input.get();
//	input.get();
//	input.get();
	string chr1;

	while(input)
	{
		
		getline(input, chr1);
		cout<<chr1<<endl;
		if(!input)
		{
			break;
		}
	}
	input.close();
	
	return 0;
}


