#pragma once
#include<string>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"D:\cworkspace\Exception\exception.h"
using namespace std;

template <class T>
class simNode{
	template <class U>
	friend class simChian;
	
	
	public:
		T data;
		simNode<T>* next;
	
		simNode(int i=rand()%50 + 1);
	simNode<T>& operator=(const simNode<T>& x);
	void Out(){
		cout<<data<<endl;
	}
	bool operator!=(const simNode<T>& x);
//	simNode<T>& operator = (simNode<T>& a,const simNode<T>& b);
};

//template <class T>
//simNode<T>& operator = (simNode<T>& a,const simNode<T>& b){
//	a.data = b.data;
//	a.next = b.next;
//	return a;
//}
template <class T>
bool simNode<T>::operator!=(const simNode<T>& x){
	return data!=x.data;
}


template <class T>
simNode<T>& simNode<T>::operator=(const simNode<T>& x){
	data = x.data;
	next = x.next;
	return *this;
}




template <class T>
simNode<T>::simNode(int i){
	data =i;
	next = 0;
}

template <class T>
class simChian{
	public:
		simNode<T>* f/irst,*End;
		simChian();
//	~simChian();
		simChian<T>& Append(const T&);
		void Output(ostream& out)const;
		int Length()const;
		simChian<T>& Insert(int k,const simNode<T>& data);
		simChian<T>& Delete(int k,simNode<T>& save);
		
};
template <class T>
simChian<T>& simChian<T>::Insert(int k,const simNode<T>& x){
	if(k<0)
		throw bound_err("k<0!!");
	if(k==1 && !first){
		simNode<T>* current = new simNode<T>;
		first = End = current;	
		return *this;
	}
	if(k==1 && first){
		simNode<T>* current = new simNode<T>;
		current->data = x.data;
		current->next = first;
		first = current;
		return *this;
	}
	else{
		simNode<T>* pre = first;
		for(int index=1;pre && index<k-1;index++)
			pre = pre->next;
		if(pre && pre->next){
			simNode<T>* newnode = new simNode<T>;
			*newnode =x;
			newnode->next = pre->next;
			pre->next = newnode;
			return *this;
		}
		throw bound_err();
	}		
	
}



template <class T>
simChian<T>& simChian<T>::Delete(int k,simNode<T>& save){
	if(k<0 || !first)
		throw bound_err("k<0 || !first ");
	simNode<T>* current;
	if(k==1){
		current =first;
		save = *current;
		first = first->next;
		delete current;
		return *this;
	}
	else{
		simNode<T>* pre = first;
		for(int index=1;pre && index<k-1;index++)
			pre = pre->next;
		if(pre && pre->next){
			current =pre->next;
			save = *current;
			pre->next = pre->next->next;
			delete current;
			return *this;
		}
		throw bound_err();
	}	
	
}






template <class T>
int simChian<T>::Length()const{
	short int index =0;
	simNode<T>* current = first;
	while(current)
	{
		index++;
		current = current->next;
	}
	return index;
}




template <class T>
simChian<T>::simChian(){
	first =NULL;
	End=NULL;
}

template <class T>
void simChian<T>::Output(ostream& out)const{
	int index =0;
	simNode<T>* current=first;
	while(current){
		index++;
		out<<"index: "<<index<<" data:"<<current->data<<endl;
		current = current->next;
	}
}



template <class T>
simChian<T>& simChian<T>::Append(const T& x){
	T* current = first;
	if(!first){
		T* newnode=new T;	
		newnode.operator=(x);
		first = newnode;
		End =newnode;
	}
	else{
		T* newnode=new T;
		newnode.operator=(x);
		End->next = newnode;
		End =newnode;
	}
}

template <class T>
ostream& operator<<(ostream& out, simChian<T> x){
	x.Output(out);
	return out;
}

