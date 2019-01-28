#include<iostream>
#include"D:\cworkspace\Exception\exception.h"
using namespace std;

template<class T>
class Node{
	template<class U>
	friend class LinkedQueue;
	private:
		T data;
		Node<T>* next;	

};




template<class T>
class LinkedQueue{
	private:
		Node<T>* front,*rear;	
	public:
		LinkedQueue(){front = rear =0;
		}
		~LinkedQueue();
		bool isEmpty()const{return ((front)? false : true);
		}
		bool isFull()const;
		T First()const;
		T Last()const;
		LinkedQueue<T>& Add(const T& x);
		LinkedQueue<T>& Delete(T& save);
		
};


template<class T>
LinkedQueue<T>::~LinkedQueue(){
	Node<T>* current = front;
	while(front){
		current = front->next;
		delete front;
		front = current;
	}	
	
}

template<class T>
bool LinkedQueue<T>::isFull()const{
	Node<T>* newnode;
	try{
		newnode = new Node<T>;
		delete newnode;
		return false;
	}
	catch(...){
		return true;
	}
}

template<class T>
T LinkedQueue<T>::First()const{
	if(isEmpty())throw bound_err();
	return front->data;
}

template<class T>
T LinkedQueue<T>::Last()const{
	if(isEmpty())throw bound_err();
	return rear->data;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x){
	if(isFull()) throw NoMem();
	Node<T>* newnode  = new Node<T>;
	newnode->data = x;
	newnode->next = 0;
	
	if(front){
	
		rear->next = newnode;
		rear = newnode;
	}
	else
		front = rear = newnode;
	return *this;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& save){
	if(isEmpty()) throw bound_err();
	Node<T>* current = front;
	save = front->data;
	front = front->next;
	delete current;
	return *this;
}

void Output(int& minH, int& minQ, LinkedQueue<int> H[],int k, int n){
	int data;
	H[minQ].Delete(data);
	cout<<"Move car"<<minH<<"from holding track"<<minQ<<"to output"<<endl;
	
	minH+=2;
	for(int i =1; i<=k; i++){
		if(!H[i].isEmpty() && (data=H[i].First()) < minH){
			minH =data;
			minQ =i;
		}
	}
		
			
}
bool Hold(int c, int& minH , int& minQ, LinkedQueue<int> H[], int k){
	int BestTrack =0,
		BestLast =0,
		x;
	for(int i=1 ; i<= k; i++){
		if(!H[i].isEmpty()){
			x = H[i].Last();
			if(c> x && x> BestLast){
				BestLast = x;
				BestTrack =i;	
			}
			
		}
	}
	
	
}

