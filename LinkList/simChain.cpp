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
	template <class U>
	friend class simChian;
	private:
		T data;
		simNode<T>* next;
	public:
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
		simNode<T>* first,*End;
		simChian();
//	~simChian();
		simChian<T>& Append(const T&);
		void Output(ostream& out)const;
		int Length();
		simChian<T>& Insert(int k,const simNode<T>& data);
		simChian<T>& Delete(int k,simNode<T>& save);
		void BinSort(int range);
};


template <class T>
void simChian<T>::BinSort(int range){
	simNode<T>** bottom,**top;
	int index;
	bottom = new simNode<T>*[range+1];
	top = new simNode<T>*[range+1];
	for(index = 0; index<range+1;index++)
		bottom[index] =0;
	for(;first;first = first->next){
		index = first->data;
		if(bottom[index]){
			top[index]->next = first;  //NO new??
			top[index] =first;
		}
		else
			bottom[index] = top[index] = first;

	}
	simNode<T>* y = 0;
	for(index = 0; index<=range;index++){
		if(bottom[index]){
			if(y)
				y->next = bottom[index];
			else
				first = bottom[index];
			y = top[index];	
		}
	if(y)
		y->next =0;
			
		
	}
	delete [] bottom;
		delete [] top;	
}		



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
int simChian<T>::Length(){
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
int main(){
	try{
	
		srand(time(NULL));
//		simChian<int> s1;
//		for(int i=0; i<5; i++){
//			simNode<int> n1;
//			s1.Insert(1,n1);
//		}
//		simNode<int> save(0);
//		cout<<s1;
//		s1.Delete(5,save);
//		cout<<s1;
//		save.Out();
		simChian<int> s1;
		for(int i =0; i<10; i++){
			simNode<int> n1;
			s1.Insert(1,n1);
		}
		cout<<s1;
		cout<<"After sort\n";
		s1.BinSort(50);
		cout<<s1;
	}
	catch(bound_err err){
		cerr<<err.what<<endl;
	}
	catch(...){
		cerr<<"other error"<<endl;
	}
}
