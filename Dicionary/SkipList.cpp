#include<iostream>


using namespace std;

template <class E, class K>
class SkipNode{
	template<class T,class U>
	friend  class SkipList;
	private:
		SkipNode<E,K>** link;
	public:
		SkipNode(int size){
			link = new SkipNode<E,K>*[size];
		}	 
		~SkipNode(){
			delete [] link;
		}
		E data;
};

template <class E, class K>
class SkipList{
	private:
		int Level();
		SkipNode<E,K>* SaveSearch(const K& k);
		int MaxLevel;
		int Levels;
		int CutOff;
		K TailKey;
		SkipNode<E,K>* head;
		SkipNode<E,K>* tail;
		SkipNode<E,K>** last;
	public:
		SkipList(K large, int MaxE = 10000, float p =0.5);
		~SkipList();
		bool Search(const K& k,E& e)const;
		SkipList<E,K>& Insert(const E& e);
		SkipList<E,K>& Delete( const K& k,E& e);	
};

template <class E, class K>
SkipList<E,K>::SkipList(K large, int MaxE , float p ){
	CutOff = p * RAND_MAX;
	MaxLevel = ceil(log(MaxE) / log(1/p)) -1;
	TailKey = Large;
	randomize();
	Levels =0;
}
