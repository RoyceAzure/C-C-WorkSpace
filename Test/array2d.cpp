#include<iostream>

using namespace std;


template<typename T,size_t M,size_t N>
void fnPrint2DArray(T (&arr)[M][N])
{
	for(size_t i=0;i<M;++i)
    {
		for(size_t j=0; j<N; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int arr2d[3][2] = {{1,2},{3,4},{5,6}};
	fnPrint2DArray(arr2d);
	return 0;
}
