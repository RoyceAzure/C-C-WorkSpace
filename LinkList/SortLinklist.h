#pragma once
#include"D:\cworkspace\general\random.h"
#include<stdlib.h>
#include<iostream>
#include "D:\cworkspace\LinkList\simChain.h"
#include "D:\cworkspace\Exception\exception.h"
#include<string>
using namespace std;

class DataNode {
	friend ostream& operator<<(ostream&, const DataNode&);
	template <class T>
	friend class simChian;
	template <class T>
	friend class simNode;
private:
	
public:
	int score;
	string name;
	
	bool operator !=(DataNode x)const {
		return (score != x.score || name != x.name);
	}
	DataNode();
	DataNode(int d1,string n){
		score =d1;
		name =n;
	}
	void setScore(int x);
	operator int()const {
		return score;
	}
	 operator string(){
		return name;
	}
	void setName(string x);
	void operator =(DataNode x){
		score = x.score;
		name = x.name;
	}
};
ostream& operator <<(ostream& out, const DataNode& node) {
	out << "name:" << node.name << " score:" << node.score << endl;
	return out;
}


DataNode::DataNode() {
	score = rand() % 50 + 1;
	name = random_string();
}
void DataNode::setScore(int x) {
	score = x;
}
void DataNode::setName(string x) {
	name = x;
}

/*       SORT             */
// Sort simNode

void BinSort(simChian<DataNode>& x, int range) {
	int len = x.Length();
	DataNode save;
	simChian<DataNode>* Bin;
	Bin = new simChian<DataNode>[range +1];
	for(int i=1; i<=len; i++){
		x.Delete(1,save);
		Bin[save.score].Insert(1,save);
	}
	for(int j=range;j>=0;j--)
		while(Bin[j].first){
			Bin[j].Delete(1,save);
			x.Insert(1,save);
		}
		delete [] Bin;
}





//int main() {
//	try{
//	
//		srand(time(NULL));
//		simChian<DataNode> s1;
//		for(int i=0; i<50; i++)
//		{
//			DataNode n1;
//			s1.Insert(1,n1);
//		}
//		cout<<"Before sort!!";
//		cout<<s1;
//		cout<<"After sort!!";
//		s1.StabilityBinSort(50);
//		cout<<s1;
//		
//		
//		
//	
//		
//	}
//	
//	catch(bound_err err){
//		cerr<<err.what<<endl;
//	}
//	catch(Array_bound_err err){
//		cerr<<err.what<<endl;
//	}
//}
