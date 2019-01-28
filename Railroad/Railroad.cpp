#include<iostream>
#include"D:\cworkspace\Stack\SimpleLinked Stack.h"
#include"D:\cworkspace\general\random.h"
using namespace std;

LinkedStack<int> result;

LinkedStack<int>* HoldArray;
int* Target;
const HoldNumber = 3;
const carN = 10;
bool Initilize(){
	try{
		Target = new int[carN];
		HoldArray = new LinkedStack<int>[HoldNumber];
		for(int i =0; i<carN; i++)
			Target[i] = rand()%50 +1;
		cout<<"Success Initilized!!"<<endl;
		return true;
	}
	catch(...){
		cerr<<"Error Happend!!\n";
		return false;
	}
	
	
}


void ClearTarget(){
	int NowOut =1;
	for(int i=0; i<N; i++){
		if(target[i]==NowOut)
			result.Push(target[i]);
		else{
		
			}
		}
	}
}

void PandC(){
	bool hasset=0;
	
	for(int i=0; i<HoldNumber; i++){
		if(HoldArray[i].isempty()){
			hasset =1
			HoldArray[i].Push(target[i]);
		}
	if(hasset==0){  //No empty
		
	}
	
    
}

int main(){
	

	int a[10] = {2,3,9,4,6,8,7,1,5};  //test
	
	
//	if(Initilize(3,10))
//	for(int i =0; i<10; i++)
//		cout<<Target[i]<<endl;
		
//	ClearTarget(HoldArray,result,Target);
	return 0;
}

