#include<iostream>
#include"D:\cworkspace\Exception\exception.h"
#include"D:\cworkspace\general\random.h"
#include"D:\cworkspace\LinkList\linerList.h"

template <class T>
class Stack:private LinearList<T>{
	public:
		Stack(int MaxSize=10):LinearList<T> (MaxSize){
		}
		bool IsEmpty()const{LinearList<T>::IsEmpty();}
		bool IsFull()const{return LinearList<T>::length==LinearList<T>::MaxSize;}
	
		T Top()const{
			if(IsEmpty())
				throw bound_err();
			T data;
			find(1,data);
			return data;
		}
		Stack& Add(T& data){
			Insert(1,data);
			return *this;
		}
		
		Stack& Delete(T& save){
			LinearList<T>::Delete(1,save);
			return *this;
		}
};


int main(){
	Stack<int> s1;
	srand(time(NULL));
	int save;
	for(int i=0; i<10;i++)
	s1.Insert(1,rand()% 50 +1);
	cout<<s1<<endl;
	s1.Delete(5,save);
	cout<<s1;
	
    cout<<save;
}
