#include <stdio.h>
#include <stdlib.h>


class base{
	int data;
};
class tire1 : public base{
	public:
		virtual void print()
		{
			printf("tire1\n");
		}
};
class tire2 : public tire1{
	public:
		void print()
		{
			printf("tire2\n");
		}
};



int main(void) {
	tire2 t2;
	tire1 *ptr = &t2;
  	ptr->print();
    
	return 0;
}
