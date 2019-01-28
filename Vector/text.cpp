#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> strings(5);
	strings[3] = "dog";
	// try
	// {
	// 	cout<<strings.at(10)<<endl;
	// }
	// catch(std::out_of_range &e)
	// {
	// 	printf("%s\n",e.what() );
	// 	printf("Fuck off!!\n");
	// }
	//
	int a = 50;
	const string str1 = "abcdefg";
	printf("%x\n",&str1);
	printf("%x\n", str1);

	printf("%d\n", str1.size());

	printf("%d\n", str1.capacity());
	for(string::const_iterator it = str1.begin(); it!=str1.end(); it++)
	{
		printf("%c", *it);
	}

	return 0;
}
