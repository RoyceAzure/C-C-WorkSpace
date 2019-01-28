#pragma once
#include"D:\cworkspace\general\random.h"
#include<stdlib.h>
#include<iostream>
#include "D:\cworkspace\LinkList\simChain.h"
#include "D:\cworkspace\Exception\exception.h"
#include<string>
using namespace std;






/*       SORT             */
// Sort simNode
template<class T>
void BinSort(simChian<T>& x, int range) {
	int len = x.Length();
	simNode<T> save;
	simChian<T>* Bin;
	Bin = new simChian<T>[range +1];
	for(int i=1; i<=len; i++){
		x.Delete(1,save);
		Bin[save.data].Insert(1,save);
	}
	for(int j=range;j>=0;j--)
		while(Bin[j].first){
			Bin[j].Delete(1,save);
			x.Insert(1,save);
		}
		delete [] Bin;
}





int main() {
	try{
	
		srand(time(NULL));
		simChian<int> s1;
		for(int i=0; i<5; i++)
		{
			simNode<int> n1;
			s1.Insert(1,n1);
		}
		cout<<"Before sort!!\n";
		cout<<s1;
		
//		simNode<int> save;
//		s1.Delete(9,save);
//		
		cout<<"After sort!!\n";
		BinSort(s1,50);
		cout<<s1<<endl;
//		cout<<save.data;
		
		
	
		
	}
	
	catch(bound_err err){
		cerr<<err.what<<endl;
	}
	catch(Array_bound_err err){
		cerr<<err.what<<endl;
	}
}
