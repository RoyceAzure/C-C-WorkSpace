#include<iostream>
#include"D:\cworkspace\Exception\exception.h"
#include"D:\cworkspace\general\random.h"
template<class T>
class LinearList{   //array
	public:
		LinearList(int Maxsize=10);
		~LinearList(){delete [] element;
		}
		bool IsEmpty()const{return length==0;}
		int Length()const{return length;}
		bool find(int k,T& x)const;
		int search( const T& x)const;
		LinearList<T>& Delete(int k,T& x);
		LinearList<T>& Insert(int k,const T& x);
		void Output(ostream& out)const;
	protected:
		int length;
		T* element;
		int MaxSize;
};

template<class T>
LinearList<T>::LinearList(int Maxsize){
	this->MaxSize = Maxsize;
	element = new T[Maxsize];
	length =0;
}

template<class T>
bool LinearList<T>::find(int k,T& x)const{
	if(k<0 || k>length)
		return false;
	x= element[k-1];
	return true;
}

template<class T> //search index
int LinearList<T>::search(const T& x)const{
	for(int i=0; i<length; i++)
		if(element[i]==x)
		{
			cout<<"find!! \n";
			return ++i;
		}
	return false;
}

template<class T> //search index
LinearList<T>& LinearList<T>::Delete(int k,T& x){
	if(find(k,x)){
		for(int i=k-1;i<length-1;i++){
			element[i]=element[i+1];
		}
		return *this;
	}
	throw bound_err(); 
}


template<class T> 
LinearList<T>& LinearList<T>::Insert(int k,const T& x){
	if(k<0 || k>length)
		bound_err();
	if(length==MaxSize )
	throw NoMem();
	
	for(int i=length;i>=k-1;i--){
		element[i]=element[i-1];
	}
	element[k-1] = x;
	length++;
	return *this;
}
template<class T>
void LinearList<T>:: Output(ostream& out)const{
	for(int i=0; i<length; i++)
		cout<<element[i]<<endl;
}
template<class T>
ostream& operator<<(ostream& out,LinearList<T>& x){
	x.Output(out);
	return out;
}

//int main(){
//	srand(time(NULL));
//	int save;
//	LinearList<int> L;
//	for(int i=0; i<10;i++)
//	L.Insert(1,rand()% 50 +1);
//	cout<<L<<endl;
//	L.Delete(5,save);
//	cout<<L;
//	
//    cout<<save;
//}

