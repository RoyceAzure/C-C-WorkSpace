#include<iostream>
#include"D:\cworkspace\Exception\exception.h"
#include"D:\cworkspace\general\random.h"
#include"D:\cworkspace\LinkList\linerList.h"

using namespace std;

template<class T>
class BaseStack{
	private:
		int top;
		int Maxtop;
		T* stack;
	public:
		BaseStack(int Maxsize=10);
		~BaseStack(){delete [] stack;
		}
		bool isEmpty()const{return top==-1;
		}
		bool isFull()const{
			return top==Maxtop;
		}
		T Top()const;
		BaseStack<T>& Add(const T& data);
		BaseStack<T>& Delete(T& save);
};

template<class T>
BaseStack<T>::BaseStack(int Maxsize){
	Maxtop = Maxsize-1;
	stack =new T[Maxtop];
	top = -1;
}

template<class T>
T BaseStack<T>::Top()const{
	if(isEmpty())throw bound_err();
	return stack[top];
}

template<class T>
BaseStack<T>& BaseStack<T>::Add(const T& data){
	if(isFull())throw bound_err();
	stack[++top] = data;
	return *this;
}

template<class T>
BaseStack<T>& BaseStack<T>::Delete(T& save){
	if(isEmpty())throw bound_err();
	save=stack[top--] ;
	return *this;
}
