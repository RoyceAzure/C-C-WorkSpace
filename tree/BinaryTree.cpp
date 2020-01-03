#include<iostream>
#include"D:/WorkSpace/C++/C-C-WorkSpace/general/random.h"

using namespace std;
template<class T>
class BinaryTreeNode{
	template <class U> 
	friend void Build(BinaryTreeNode<U>*,short);
	private:
		T data;
		BinaryTreeNode<T> *left,*right;
	public:
	
		BinaryTreeNode(){
			left = right =0;
		}	
		BinaryTreeNode(const T& e){
			data =e;
			left = right =0;
		}
		BinaryTreeNode(const T& e,const BinaryTreeNode<T>* l,const BinaryTreeNode<T>* r){
			data =e;
			left = l;
			right = r;
		}
		void vist()const{
			cout<<data<<endl;
		}
		
		void preOrder()const{  //if exist then vist
			if(this){
				this->vist();
				this->left->preOrder();
				this->right->preOrder();
			}
		}
		
		void InOrder()const{  //if no leftchild ,vist
			if(this){
				this->left->InOrder();
				this->vist();
				
				this->right->InOrder();
			}
		}
		
		void PostOrder()const{  //when no child , vist current
			if(this){
				this->left->PostOrder();
				
				
				this->right->PostOrder();
				this->vist();
			}
		}
		
		void Infix()const{
			if(this){
					cout<<'(';
					this->left->Infix();
					cout<<this->data;
					this->right->Infix();
					cout<<')';
			}
		}
		
//		void LevelOrder()const{
//			
//		}
		
		
};

template<class T>
void Build(BinaryTreeNode<T> *root,short degree){
	BinaryTreeNode<T> *newnode;
	root->data = rand()%100+1;
	if(degree>0){
		short bridge = rand()%3+1;
		switch(bridge){
			
			case 1://left
				newnode = new BinaryTreeNode<T>;
				root->left = newnode;
				Build(root->left,degree-1);
				break;
			case 2://right
				newnode = new BinaryTreeNode<T>;
				root->right = newnode;
				Build(root->right,degree-1);	
				break;
			case 3:
				newnode = new BinaryTreeNode<T>;
				root->left = newnode;
				Build(root->left,degree-1);
		
				BinaryTreeNode<T> *newnodeR = new BinaryTreeNode<T>;
				root->right = newnodeR;
				Build(root->right,degree-1);	
				break;
				
		}
		
	}
	
	
}








int main(){
	srand(time(NULL));
	BinaryTreeNode<int> *test;
	test = new BinaryTreeNode<int>;
	Build(test,2);
	test->Infix();
//	cout<<"Preorder:"<<endl;
//	test->preOrder();
//	cout<<"Inorder:"<<endl;
//	test->InOrder();
//	cout<<"Postorder:"<<endl;
//	test->PostOrder();
}
