#pragma once
#include<cstdlib>
#include<iostream>
#include<assert.h>
#include<string>
#include "D:\cworkspace\Exception\exception.h"
using namespace std;

const int STACK_SIZE = 100;


template<class T>
class stack {
	private:
		int count;
		T data[STACK_SIZE];
	public:
		stack():count(0){}
		
		void push(const int ) throw (bound_err);
		T pop() throw(bound_err);
};
template<class T> inline void stack<T>::push(const int item) throw (bound_err) {
	try {
		if ((count < 0) || (count >= sizeof(data) / sizeof(data[0])))
		{
			throw bound_err("Push overflows stack");
		}
		data[count] = item;
		cout << "Push data[count]:" << count << "item:" << item << endl;
		++count;
	}
	catch(bound_err & err){
		cerr << "Error Bounds exceeded\n";
		cerr << "Reason:" << err.what<<endl;
		exit(8);
	}
	catch (...) {
		cerr << "Error unexcepted exception!!\n";
		exit(8);
	}
}

template<class T> inline T stack<T>::pop()throw (bound_err) {
	try {
		--count;
		if ((count < 0) || (count >= sizeof(data) / sizeof(data[0])))
		{
			throw bound_err("Pop overflows stack");
		}
		return data[count];
	}
	catch (bound_err & err) {
		cerr << "Error Bounds exceeded\n";
		cerr << "Reason:" << err.what << endl;
		exit(8);
	}
	catch (...) {
		cerr << "Error unexcepted exception!!\n";
		exit(8);
	}
}

int main(){
	stack<int> s1;
	for(int i=0 ;i<150; i++){
	
		s1.push(i);
	}
	
}

