#include<iostream>
#include"D:\cworkspace\LinkList\simpLinked.h"
#include"D:\cworkspace\general\random.h"
template<class T>
class LinkedStack:private SimpLink<T>{
	private:
		Node<T>* top;
	public:
		LinkedStack():top(0){
		}
		~LinkedStack();
		
		bool isEmpty()const{return top==0;
		}			
		bool isFull()const;
		T Top()const;
		LinkedStack<T>& Push(const T& x);
		LinkedStack<T>& Pop(T& x);
};

template<class T>
LinkedStack<T>::~LinkedStack(){
	Node<T>* next;
	while(top){
		next = top->next;
		delete top;
		top = next;
	}
}

template<class T>
bool LinkedStack<T>::isFull()const{
	try{
		Node<T>* newnod = new Node<T>;
		delete newnod;
		return false;
	}
	catch(...){
		return true;
	}
}

template<class T>
T LinkedStack<T>::Top()const{
	if(isEmpty()) throw bound_err();
	return top->data;
}

template<class T>
LinkedStack<T>& LinkedStack<T>::Push(const T& x){
	if(isFull()) throw NoMem();
	Node<T>* newnod = new Node<T>;
	newnod->data = x;
	newnod->next = top;
	top = newnod;
	return *this;
}

template<class T>
LinkedStack<T>& LinkedStack<T>::Pop(T& x){
	if(isEmpty()) throw bound_err();
	x = top->data;
	Node<T>* p = top;
	top = top->next;
	delete p;
	return *this;
}

int main(){
	srand(time(NULL));
	LinkedStack<int> L1;
	Node<int> n1;
	L1.Push(20);
}
