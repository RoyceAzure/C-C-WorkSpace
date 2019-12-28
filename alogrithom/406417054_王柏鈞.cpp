#include<iostream>
#include<math.h>
#include <algorithm>
#include <time.h>
#define MAX 500

typedef unsigned short uint;

class item{
	private:
		char name;
		uint _benefit;
		uint _weight;
		uint _cost;
	
	public:
		friend bool cost_compare( const item& , const item& );
		item()
		{
			
		}
		item(char n, uint b, uint w):name(n), _benefit(b), _weight(w)
		{
			_cost = int(ceil((_benefit/_weight)+0.5));
		}
		bool operator< ( const item& i);
		void print_data();
		uint get_cost()
		{
			return _cost;
		}
		uint get_weight()
		{
			return _weight;
		}
		uint get_benefit()
		{
			return _benefit;
		}
		char get_name()
		{
			return name;
		}
};

bool item::operator<(const item& i)
{
	return _benefit > i._benefit;  //trick , i used >
}

void item::print_data()
{
	printf(" %c with weight %d and value %d,",name, _weight, _benefit);
} 


bool cost_compare( const item& a, const item& b)
{
	return a._cost > b._cost;
}

template <class T>
void swaps(T& a1,T& a2)
{
	T tmp=a1;
	a1=a2;
	a2=tmp;
}

template <class T>
void BubbleSort(T a[],int length)
{
	bool swaped =true;
	for(int i=length; i>0&&swaped ; i--)
	{
		swaped =false;
		for(int j =0; j<i; j++)
		{
			if(cost_compare(a[j], a[j+1]))
			{
				swaps(a[j],a[j+1]);
				swaped = true;
			}
		}
	}
}



void (*Knapsack)(item items[4], int);    

void Knapsack1_value(item items[4], int c)
{
	uint total_value = 0;
	uint total_weight = 0;
	char Catch[4];
	uint j = 0;
	
	for(uint i = 0; i<4; i++)
	{
		if(c-items[i].get_weight()>0)
		{
			c=	c- items[i].get_weight();
			Catch[j] = items[i].get_name();
			total_value+= items[i].get_benefit();
			total_weight+= items[i].get_weight();
			j++;
			printf("\n");
		}
	}
	printf("Using Benefit only catch ");
	for(uint i = 0; i<j; i++)
	{
		printf("%c ",Catch[i]);
	}
	printf("the total benefit value is %d, and total weight is %d\n", total_value, total_weight);
}

void Knapsack1_cost(item items[4], int c)
{
	uint total_value = 0;
	uint total_weight = 0;
	char Catch[4];
	uint j = 0;
	
	for(uint i = 0; i<4; i++)
	{
		if(c-items[i].get_weight()>0)
		{
			c=	c- items[i].get_weight();
			Catch[j] = items[i].get_name();
			total_value+= items[i].get_benefit();
			total_weight+= items[i].get_weight();
			j++;
		}
	}
	printf("Using Unit Benefit/Weight only catch ");
	for(uint i = 0; i<j; i++)
	{
		printf("%c ",Catch[i]);
	}
	printf("the total benefit value is %d, and total weight is %d\n", total_value, total_weight);
}

void greedy_method_demo(item items[4], int c = 500)
{
	
	printf("Original Data is Knapsack Capacity is %d\n, Three items A withweight 300 and value 1000,\n B with weight 200 and value 200,\n C with weight 400 and value 600,\nD withweight 100 and value 400",c);	
	std::sort(items,items+4);
	Knapsack = Knapsack1_value;
	Knapsack(items, c);
	
	BubbleSort(items, 4);
	Knapsack = Knapsack1_cost;
	Knapsack(items, c);	
	printf("\n");
}





int main()
{
	srand( time(NULL) );
	item A('A', 1000,300);
	item B('B', 200,200);
	item C('C', 600,400);
	item D('D', 400,100);
	item itemsA[4];
	itemsA[0] = A;
	itemsA[1] = B;
	itemsA[2] = C;
	itemsA[3] = D;
	greedy_method_demo(itemsA);
	printf("/===============================================/\n");
	item A2('A', 500,150);
	item B2('B', 200,100);
	item C2('C', 450,300);
	item D2('D', 350,200);
	item itemsB[4];
	itemsB[0] = A2;
	itemsB[1] = B2;
	itemsB[2] = C2;
	itemsB[3] = D2;
	
	int c = rand() % (700 - 400 + 1) + 400;
	greedy_method_demo(itemsB, c);
	printf("/===============================================/\n");
	item A3('A', 250,100);
	item B3('B', 200,200);
	item C3('C', 350,300);
	item D3('D', 450,400);
	item itemsC[4];
	itemsC[0] = A3;
	itemsC[1] = B3;
	itemsC[2] = C3;
	itemsC[3] = D3;
	c = rand() % (700 - 400 + 1) + 400;
	greedy_method_demo(itemsB, c);
//	for(int i =0; i<4; i++)
//		items[i].print_data();
}
