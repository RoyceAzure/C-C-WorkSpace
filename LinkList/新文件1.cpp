#include<iostream>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100
using namespace std;

template <class T>
class DoubleNode{
//	friend class DoubleChain;
	public:
		T data;
		DoubleNode<T> *left,*right;
};

template <class T>
class DoubleChain{
	private:
//		DoubleNode<T> data[MAX_SIZE];
		DoubleNode<T> *LeftEnd,*RightEnd;
	public:
		DoubleChain(){
			LeftEnd =0;
			RightEnd=0;
		}
//		~DoubleChain();
		int Length()const;
		bool find(int k,T& x)const;
		int Search(const T& x)const;
		DoubleChain& Delete(int k ,T& x);
		DoubleChain& Insert(int k ,const T& x);
		void Output(ostream& out) const;
		DoubleChain& Append(const T& );
};

//template <class T>
//DoubleChain<T>::~DoubleChain(){
//
//	while(LeftEnd){
//		DoubleNode<T>* pre = LeftEnd;
//		LeftEnd = LeftEnd->right;
//		if(LeftEnd==RightEnd)
//			LeftEnd=RightEnd=0;
//		delete pre;
//	}
//}

template <class T>
int DoubleChain<T>::Length()const{
	int count =0;
	DoubleNode<T>* current=LeftEnd;
	while(current){
		count++;
		if(current = RightEnd)
			break;
		current = current->right;
	}
	return count;
}

template <class T>
bool DoubleChain<T>::find(int k,T& x)const{
	if(k<0)
		return false;
	int index =0;
	DoubleNode<T>* current=LeftEnd;
	while(current && index<k){
		index++;
		current = current->right;
		if(current == RightEnd)
			break;
	}
	if(current)
	{
		x = current->data;
		return true;
	}
	return false;
}

template <class T>
int DoubleChain<T>::Search(const T& x)const{
	int index =0;
	DoubleNode<T>* current=LeftEnd;
	while(current->data!=x && current != RightEnd ){
		index++;
		current = current->right;
	}
	if(current->data == x)
	{
		return index;
	}
	return -1;
}

template <class T>
void DoubleChain<T>::Output(ostream& out)const{
	DoubleNode<T>* current=LeftEnd;
	for(int i=1;current;i++,current = current->right){
		out<<"index:"<<i<<" data:"<<current->data<<endl;
		if(current==RightEnd)
			break;
	}
}

template <class T>
ostream& operator << (ostream& out,DoubleChain<T> chain){
	chain.Output(out);
	return out;
}

template <class T>
DoubleChain<T>& DoubleChain<T>::Append(const T& x){
	DoubleNode<T>* newnode;
	if(!LeftEnd){
		newnode = new DoubleNode<T>;
		newnode->data =x;
		newnode->left=newnode->right = newnode;
		LeftEnd = RightEnd = newnode;
	}
	else{
		newnode = new DoubleNode<T>;
		newnode->data =x;
		newnode->left = RightEnd;
		newnode->right = LeftEnd;
		RightEnd->right = newnode;
		RightEnd =newnode;
	}
	return *this;
}

template <class T>
DoubleChain<T>& DoubleChain<T>::Insert(int k ,const T& x){
	DoubleNode<T>* newnode = LeftEnd;
	for(int index =0; index<k&&newnode;index++)
		newnode = newnode->right;
		if(newnode)
		{
			DoubleNode<T>* newnode2;
			newnode2->data = x;
			newnode2->left = newnode;
			newnode2->right = newnode->right;
			newnode ->right = newnode2;
			return *this;
		}
		else
			cout<<"insex out of bound!!";
		return *this;
	
	
}


int main(){
	srand( (unsigned)time(NULL) );
	DoubleChain<int> list1;
	


}

