#include<iostream>
#include<math.h>
#define MAX 500

typedef unsigned short uint;







class item{
	private:
		char name;
		uint _benefit;
		uint _weight;
		uint _cost;
	
	public:
		item(char n, uint b, uint w):name(n), _benefit(b), _weight(w)
		{
			_cost = int(ceil((_benefit/_weight)+0.5));
		}
		bool operator< ( const item& i);
		void print_data();
};

bool item::operator<(const item& i)
{
	return _benefit < i._benefit;
}

void item::print_data()
{
	printf(" %c with weight %d and value %d,",name, _weight, _benefit);
} 


bool cost_compare( const item& )
{
	
}


int main()
{
	
	
	
}
