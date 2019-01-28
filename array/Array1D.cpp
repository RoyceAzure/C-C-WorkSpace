#include<iostream>
#include"D:\cworkspace\Exception\exception.h"
#include"D:\cworkspace\general\random.h"
template<class T>
class Array1D{
	template<class U>
	friend ostream& operator<<(ostream& out,Array1D<U>& a);
	private:
		int size;
		T* element;
	public:
		Array1D(int size =0);
		
		Array1D(const Array1D<T>& v);
		~Array1D(){
			delete [] element;
		}
		T& operator[](int i) const;
		int Size(){return size;
		}
		Array1D<T>& Resize(int col);
		Array1D<T>& operator=(const Array1D<T>& v);
		Array1D<T>  operator+() const;
		Array1D<T>  operator+(const Array1D<T>& v) const;
		Array1D<T>  operator-() const;
		Array1D<T>  operator-(const Array1D<T>& v) const;
		Array1D<T>  operator*(const Array1D<T>& v) const;
		Array1D<T>& operator+=(const T& x);
		Array1D<T>& RandomArray();
		
}; 

template<class T>
Array1D<T>& Array1D<T>::Resize(int col){
	delete [] element;
	element = new T[col];
	for(int i =0; i<col; i++)
		element[i]=0;
	return *this;
}








template<class T>
Array1D<T> Array1D<T>::operator+(const Array1D<T>& v)const{
	Array1D<T> result(size);
	for(int i=0; i<size; i++)
		result[i]= element[i]+v.element[i];
	return result;
}



template<class T>
ostream& operator<<(ostream& out,Array1D<T>& a){
	for(int i =0; i<a.size; i++)
		out<<a.element[i]<<endl;
	return out;
}

//template<class T>
//ostream& operator<<(ostream& out,Array1D<T> a){
//	for(int i =0; i<a.size; i++)
//		out<<a.element[i]<<endl;
//	return out;
//}

template<class T>
Array1D<T>& Array1D<T>::RandomArray(){
	for(int i =0; i<size; i++)
		element[i] = rand()%50 +1;
	return *this;
}


template<class T>
Array1D<T>::Array1D(int size){
	if(size<0)
		throw Bad_Initilizer();
	this->size = size;
	element = new T[size];
}


template<class T>
Array1D<T>::Array1D(const Array1D<T>& v){
	size = v.size;
	element = new T[size];
	for(int i =0; i<size; i++)
		element[i] = v.element[i];
}

template<class T>   //the return can actually change the value of the array[i]
T& Array1D<T>::operator[](int i)const{
	if(i<=0 || i>=size) throw bound_err();
	return element[i-1];
}

template<class T>
Array1D<T>& Array1D<T>::operator=(const Array1D<T>& v){
	if(this != &v){
		size = v.size;
		delete [] element;
		element = new T[size];
		for(int i =0; i<size; i++)
			element[i] = v.element[i];
	}
	return *this;
}

template<class T>
Array1D<T> Array1D<T>::operator-(const Array1D<T>& v)const{
	if(size!= v.size) throw Size_MisMatch();
	
	Array1D<T> result(size);
	for(int i=0; i<size; i++)
		result.element[i] = element[i]-v.element[i];
	return result;
}

template<class T>
Array1D<T> Array1D<T>::operator*(const Array1D<T>& v)const{
	if(size!= v.size) throw Size_MisMatch();
	
	Array1D<T> result(size);
	for(int i=0; i<size; i++)
		result.element[i] = element[i]*v.element[i];
	return result;
}

template<class T>  //Turn Negative
Array1D<T> Array1D<T>::operator-()const{
	Array1D<T> result(size);
	for(int i=0; i<size; i++)
		result.element[i] = -element[i];
	return result;
}

template<class T>
Array1D<T>& Array1D<T>::operator+=(const T& x){
	for(int i=0; i<size; i++)
		element[i]+= x;
	return *this;
}

/*-------------------------------2D-------------------------------------------------------*/
template<class T>
class Array2D{
	template<class U>
	friend ostream& operator<<(ostream& out,Array1D<U>& a);
	private:
		int rows,cols;
		Array1D<T>* row;
	public:
		Array2D(int r=0,int c =0);
		
		Array2D(const Array2D<T>& v);
		~Array2D(){
			delete [] row;
		}
		
		int Rows()const{return rows;
		}
		int Cols()const{return cols;
		}
		
		Array1D<T>& operator[](int i)const;
		Array2D<T>& operator=(const Array2D<T>& v);
		Array2D<T>  operator+() const;
		Array2D<T>  operator+(const Array2D<T>& v) const;
		Array2D<T>  operator-() const;
		Array2D<T>  operator-(const Array2D<T>& v) const;
		Array2D<T>  operator*(const Array2D<T>& v) const;
		Array2D<T>& operator+=(const T& x);
		Array2D<T>& RandomArray();
		
}; 


template<class T>
Array2D<T>::Array2D(int r,int c){
	if(r<0 || c<0) throw Bad_Initilizer();
	
	
	rows =r;
	cols = c;
	row = new Array1D<T> [rows]; 
	for(int i=0;i<rows;i++)
		row[i].Resize(cols);
}

template<class T>
Array2D<T>::Array2D(const Array2D& m){
	rows = m.rows;
	cols = m.cols;
	
	row = new Array1D<T>[rows];
	for(int i=0;i<rows;i++)
		row[i].operator=(m.row[i]) ;
}	

template<class T>
Array1D<T>& Array2D<T>::operator[](int i)const{
	if(i<0 || i> rows) throw bound_err();
	return row[i-1];
}

template<class T>
Array2D<T> Array2D<T>::operator-(const Array2D<T>& m)const{
	if(rows !=m.rows || cols != m.cols ) throw Size_MisMatch();
	
	Array2D<T> result(rows,cols);
	for(int i=0;i<rows;i++)
		result[i] = row[i] - m.row[i];
	return result;
}


template<class T>
Array2D<T> Array2D<T>::operator*(const Array2D<T>& m)const{
	if(rows !=m.rows || cols != m.cols ) throw Size_MisMatch();
	
	Array2D<T> result(rows,cols);
	for(int i=0;i<rows;i++)
		result[i] = row[i]*m.row[i];
	return result;
}





int main(){
	srand(time(NULL));
	Array1D<int> a1(0);
	Array1D<int> b1(5);
	Array1D<int> c1(5);
	a1.RandomArray();
	b1.RandomArray();
	cout<<a1;
	cout<<endl;
	cout<<b1;
	cout<<endl;
	int a=50;
	
	cout<<b1.operator+=(a);

	
}


