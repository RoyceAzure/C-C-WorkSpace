#include<iostream>
#include<exception>
#include"D:\cworkspace\Exception\exception.h"
#include"D:\cworkspace\general\random.h"

using namespace std;
template<class T>
class Node{
	template<class U>
	friend class LinkedStack;
	private:
		T data;
		Node<T>* next;
	public:
		Node(int x){
			data = x;
			next = 0;
		}
		Node(){
			data = rand()% 50 +1;
			next = 0;
		}
	Node& operator =(Node& x){
		data = x.data;
		next = x.next;
		return *this;
		}	
	Node& out(){
			cout<<data<<endl;
			return *this;
		}	

};

template<class T>
class LinkedStack{
	template<class U>
	friend ostream& operator<<(ostream& out,LinkedStack<U>& x);
	private:
		Node<T>* top;
	public:
		LinkedStack(){top = 0;
		}
		~LinkedStack();
		bool isempty() const{return top==0;}
		bool isFull()const;
		T Top()const;
		LinkedStack<T>& Push(const T& x);
		LinkedStack<T>& Pop(T& x);
		void Out(ostream& out){
			Node<T>* current =top;
			while(current){
				out<<current->data<<endl;
				current = current->next;
		}
	}
		
};

template<class T>
LinkedStack<T>::~LinkedStack(){
	Node<T>* next ;
	while(top){
		next = top->next;
		delete top;
		top = next;
	}
}

template<class T>
bool LinkedStack<T>::isFull()const{
	try{
		Node<T>* node = new Node<T>;
		delete node;
		return false;
	}
	catch(bad_alloc){
		return true;
	}
}



template<class T>
T LinkedStack<T>::Top()const{
	if(isempty())
		throw bound_err();
	return top->data;
}

template<class T>
LinkedStack<T>& LinkedStack<T>::Push(const T& x){
	Node<T>* newnode = new Node<T>;
	newnode->data = x;
	newnode->next = top;
	top = newnode;
	return *this;
}


template<class T>
LinkedStack<T>& LinkedStack<T>::Pop(T& save){
	if(isempty()) throw bound_err();
	save = top->data;
	Node<T>* next= top-> next ;
	delete top;
	top = next;
	return *this;
}
template<class T>
ostream& operator<<(ostream& out,LinkedStack<T>& x){
	x.Out(out);
	return out;
}


int main(){
	srand(time(NULL));

	try{
		LinkedStack<int> L1;
		Node<int> save(20);
//		Node<int> a1;
		
		int x;
		int save1=50;
		for(int i=0 ; i<10 ; i++)
		L1.Push(rand()% 50 +1);
		cout<<L1;
		for(int i=0 ; i<11 ; i++)
			L1.Pop(x);
		cout<<"------------------";
		cout<<L1;
		cout<<x;
	}
	catch(bound_err err){
		cerr<<err.what<<endl;
	}
	catch(...){
		cerr<<"some error happend!!"<<endl;
	}
}
