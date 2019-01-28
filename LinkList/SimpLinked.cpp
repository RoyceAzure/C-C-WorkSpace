#include<iostream>
#include"D:\cworkspace\general\random.h"
#include"D:\cworkspace\Exception\exception.h"
using namespace std;
template<class T>
class Node{
	template<class U>
	friend class SimpLink;
	private:
		T data;
		Node<T>* next;
	public:
		Node(int data=rand()%50 +1){
			this->data = data;
			next =0;
		}
		Node<T>& operator=( Node<T>& x);
		void Out(ostream& out)const;
};

template<class T>
Node<T>& Node<T>::operator=(Node<T>& x){
	data = x.data;
	return *this;
}
template<class T>
void Node<T>::Out(ostream& out)const{
	out<<"data: "<<data<<endl;
	
}












/*-----------------------------simLink---------------------------------------*/
template<class T>
class SimpLink{
	private:
		Node<T>* first,*End;
		int length;
	public:
		SimpLink(){
			first =0;
			length =0;
		}
		bool isEmpty(){
			return Length()==0;
		}
		int Length()const{
			return length;
		}
	Node<T>* find(int k);
	SimpLink& Apend(Node<T>& x);
	SimpLink& insert(int k,const Node<T>& x);
	SimpLink& Delete(int k,Node<T>& save);
	void Out(ostream& out)const;
};

template<class T>
Node<T>* SimpLink<T>::find(int k)
{	
	Node<T>* current = first;
	for(int index=1;current &&  index<k;current = current->next)
		index++;
	if(current)
		return current;
	throw bound_err("Can't find k index");
}






template<class T>
SimpLink<T>& SimpLink<T>::Delete(int k,Node<T>& save){
	if(k<=0 || !first || k>length)
		throw bound_err("k<0 || !first ");
	Node<T>* current;
	if(k==1){
		current =first;
		save = *current;
		first = first->next;
		delete current;
		length--;
		return *this;
	}
	else{
		Node<T>* pre = first;
		for(int index=1;pre && index<k-1;index++)
			pre = pre->next;
		if(pre && pre->next){
			current =pre->next;
			save = *current;
			pre->next = pre->next->next;
			delete current;
			length--;
			return *this;
		}
		throw bound_err();
	}	
	
}







template<class T> SimpLink<T>& SimpLink<T>::insert(int k,const Node<T>& x){
	if(k<=0)
		throw bound_err("k<0!!");
	if(k==1 && !first){
		Node<T>* current = new Node<T>;
		first = End = current;	
		length++;
		return *this;
	}
	if(k==1 && first){
		Node<T>* current = new Node<T>;
		current->data = x.data;
		current->next = first;
		first = current;
		length++;
		return *this;
	}
	else{
		Node<T>* pre = first;
		for(int index=1;pre && index<k-1;index++)
			pre = pre->next;
		if(pre && pre->next){
			Node<T>* newnode = new Node<T>;
			newnode->data =x.data;
			newnode->next = pre->next;
			pre->next = newnode;
			length++;
			return *this;
		}
		throw bound_err();
	}		
	
}








template<class T>
void SimpLink<T>::Out(ostream& out)const{
	Node<T>* current = first;
	for(int index = 1;current;current=current->next){
		out<<"index: "<<index;
		out<<"data: "<<current->data<<endl;
		index++;
	}
	
}





template<class T> SimpLink<T>& SimpLink<T>::Apend(Node<T>& x){
	Node<T>* current=first;
	if(!current){
		current = new Node<T>;
		*current = x;
		first = current;
		End = current;
		length++;
	}
	else{
		current = new Node<T>;
		*current = x;
		End->next = current;
		End = current;
		length++;
	}	
	return *this;
	
}
/*-----------------------------------------------------------------------*/
template<class T>
ostream& operator<<(ostream& out,SimpLink<T>& x){
	x.Out(out);
	return out;
}

template<class T>
ostream& operator<<(ostream& out,Node<T>& x){
	x.Out(out);
	return out;
}

int main(){
		try{
		
			srand(time(NULL));
	
			
		SimpLink<int> S1;
		
		cout<<S1.isEmpty();
		for(int i=0; i<10; i++)
		{
			Node<int> n1;
			S1.insert(1,n1);			
		}
		cout<<S1.isEmpty();
//		Node<int> save;
//		S1.Delete(11,save);
//		cout<<S1;
//		cout<<save;
//		
	}
	
	catch(bound_err err){
		cerr<<err.what;
	}
}
