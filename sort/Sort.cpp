#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<istream>
#include<vector>
#define SIZE_OF_ARRAY(ary) sizeof(ary) / sizeof(*ary)


using namespace std;


//template <class T>
//int SizeofArrray(T a[]){
//	int length = (sizeof(a)/sizeof(a[0]));
//	cout<<length;
//	return length;
//}
/*---------------------------- BASE TOOL------------------------
----------------------------------------------------------------*/
template <class T>
void swaps(T& a1,T& a2){
 T tmp=a1;
 a1=a2;
 a2=tmp;
}

int ** RandomArray2D(){
	int** a;
	static int row = rand()%40 + 10;
	static int col = rand()%40 + 10;
	a = new int* [row];
	for(int i=0; i<row; i++){
		*(a+i) = new int[col];
		for(int j=0; j<row;j++)
			*(*(a+i)+j) = rand()% 100 + 1;
	}
			
	return a;
}

int * RandomArray1D(int row){
	int* a = new int[row];
	for(int i=0; i<row; i++)
		*(a+i) = rand()% 100 + 1;
	return a;
}

int MakeRandom(int &row, int &col){
	row = rand()% 40 + 10;
	col = rand()% 40 + 10;
}
template <class T>
int Max(T a[],int length){
	int pos =0;
	for(int i=1; i<length; i++){
		if(a[pos]<a[i]){
			pos = i;
		}
	}
	return pos;
}
template <class T>
void Cout1DA(T *a,int length){
	for(int i=0;i<length;i++)
	{
		cout<<a[i]<<endl;
	}	
}

template <class T>
void Cout2DA(T **a,int length,int height){
	for(int i=0;i<length;i++)
		for(int j=0; j<height;j++)
			cout<<a[i][j];
}

template<class T>
void Make2Darray(T **&x, int rows, int cols) {
	x = new T*[rows];
	for (int i = 0; i<rows; i++) {

		x[i] = new T[cols];
		for (int j = 0; j<cols; j++) {

			x[i][j] = rand() % 100 + 1;
			std::cout << x[i][j] << std::endl;
		}
	}
}
/*---------------------------- BASE TOOL------------------------
----------------------------------------------------------------*/

/*---------------------------- Sort------------------------
----------------------------------------------------------------*/

template <class T>
void Rank(T a[],int length,int r[]){
	for(int i=0;i<length;i++)
		r[i] = 0;
	for(int i=0;i<length;i++){
		for(int j=i+1;j<length; j++)
			if(a[i]>=a[j])
				r[i]++;
			else r[j]++;
	}
}



template <class T>
void Rank_Sort(T a[],T r[],int length){
	for(int i =0; i<length;i++)
	{
		while(r[i]!=i)
		{
			int temp = r[i];
			swaps(a[i],a[temp]);
			swaps(r[i],r[temp]);
		}
	}
}

template <class T>
void Selection(T a[],int length){
	
	for(int i=length;i>0; i--){
		int max = Max(a,i);
		if(i!=max){
			swaps(a[i-1],a[max]);
		}
	}
	
}

template <class T>
void Selection2(T a[],int length){
	bool sorted = false;
	for(int size=length;size>1 &&!sorted; size--){
		int pos =0;
		sorted = true;
		for(int i=1; i<size;i++)
			if(a[pos]<=a[i])
				pos = i;
			else sorted =false;
		swaps(a[pos],a[size-1]);
	}
	
}

template <class T>
void BubbleSort(T a[],int length){
	bool swaped =true;
	for(int i=length; i>0&&swaped ; i--){
		swaped =false;
		for(int j =0; j<i; j++)
		{
			if(a[j]>a[j+1]){
				swaps(a[j],a[j+1]);
				swaped = true;
		}
	}
}
	
}

template <class T>
void Insert(T a[],int length,T &x){
	int i;
	for(i=length-1; i>=0 && x<a[i];i--)
			a[i+1] =a[i];
	a[i+1] =x;
}


template <class T>
void InsertSort(T a[],int length){
	for(int i =1; i<length ;i++){
		T t =a[i];
		Insert(a,i,t);
	}
		
}


vector<int> MaxHeapInsert(vector<int> &array, int target)
{
	int i = array.size();
	array.emplace_back(target);
	while(array[i] < target && i > 0)    //只要target 比P 還要大  就 shift, 改變i , 
	{
		array[i] = array[i%2 == 0?(i/2)-1 : i/2] ;
		i = i%2 == 0?(i/2)-1 : i/2;
	} 
	array[i] = target;
}
vector<int> MaxHeapInsertInplace(vector<int> &array, int n) //給定1個array, 做inplace insert
{
	int i = n;
	int temp = array[n];
	while(array[i] < temp && i > 0)    //只要target 比P 還要大  就 shift, 改變i , 
	{
		array[i] = array[i%2 == 0?(i/2)-1 : i/2] ;
		i = i%2 == 0?(i/2)-1 : i/2;
	} 
	array[i] = temp;
}
vector<int> CreateHeap(vector<int> &array)
{
	int n = array.size();
	for(int i = 2; i<n; i++)
	{
		MaxHeapInsertInplace(array, i);
	}
}

int DeleteHeap(vector<int> array, int n) // j用來指向child, i 為當前parent 
{
	int i = 0, j, x, temp, val;
	j = i*2+1;
	x = array[0];
	array[0] = array[n];
	while(j < n-1)  //j 必須在回圈內做改變 
	{
		if(array[j] < array[j+1])
			j = j+1;
		if(array[i] < array[j])
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i = j;
			j = j*2+1;
		}
		else
			break;
	}
	array[n] = x;
}
/*---------------------------- Sort------------------------
----------------------------------------------------------------*/

int main() {
	
	srand(time(NULL));
	int row=0,col=0;
	MakeRandom(row,col);
	int* a = RandomArray1D(row);
	InsertSort(a,row);
	
	
	Cout1DA(a,row);
 return 0;
}
