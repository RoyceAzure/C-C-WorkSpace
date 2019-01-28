#include<string>
#ifndef EXCEPTION_H
#define EXCEPTION_H





//only has member string what, because it's customs
class bound_err {
public:
	const std::string what;
	bound_err(const std::string& i_what="Out of bounds!!") :what(i_what) {}
};

class Array_bound_err {
public:
	const std::string what;
	Array_bound_err(const std::string& i_what="Array Out of index!!") :what(i_what) {}
};

template <class T>  /***Only accept in array  not pointer****/
bool isOutArrayIndex(T a[],int index) throw (Array_bound_err){
	if(sizeof(a)/sizeof(a[0])<index)
		throw Array_bound_err();
	return 0;
}

class Bad_Initilizer {
public:
	const std::string what;
	Bad_Initilizer(const std::string& i_what="Bad initilizeer: <0!!") :what(i_what) {}
};

class Size_MisMatch {
public:
	const std::string what;
	Size_MisMatch(const std::string& i_what="Size MisMatch !!") :what(i_what) {}
};

class NoMem {
public:
	const std::string what;
	NoMem(const std::string& i_what="NOMEM") :what(i_what) {}
};






#endif
