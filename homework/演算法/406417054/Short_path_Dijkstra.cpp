#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <windows.h>
using namespace std;


 class S_P_Dijkstra{
	private:
		static int posx, posy;
		int **adjacency_matrix;
		vector<int> distance, pre;
		set<int> S,T;
		int SIZE;
	public:
	  	S_P_Dijkstra(int **metrix, int size):SIZE(size){
	  		adjacency_matrix = new int *[SIZE];
			for(int i=0; i<SIZE; i++)
			{
				adjacency_matrix[i] = new int[SIZE];	
			}
			
			for(int i =0; i<SIZE; i++)
				for(int j=0; j<SIZE; j++)
				{
					adjacency_matrix[i][j] = metrix[i][j];
//					printf("%d\t",adjacency_matrix[i][j]);
				}
			printf("\n");
		};
		
		
		void gotoxy(int ,int);
		void Dijkstra(int Start);
		int find_min_cost();
 		void init(int);
 		void outPut_d();
 		void outPut_pre();
 		void outPut_set();
 		void ouptPut_all(int, int);
 		void update_dist(int);
 
 
 	
 };
 
 int S_P_Dijkstra::posx = 0;
 int S_P_Dijkstra::posy = 0;
 void S_P_Dijkstra::gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}	
 
 
 void S_P_Dijkstra::update_dist( int exp_node)
 {
 	
 	for(int j =0; j< SIZE; j++)
 	{
 		if(adjacency_matrix[exp_node][j] !=0 )
		{
			int dis = adjacency_matrix[exp_node][j] ;
			if( distance[exp_node] + dis < distance[j])
			{
				distance[j] = distance[exp_node] + dis;
				pre[j] = exp_node;
			}
		}
	}
 	
 }

 
 
 
 int S_P_Dijkstra::find_min_cost()
 {
 	int next, shorest = 9999;
 	bool is_in;
	for(int i=0 ; i<SIZE; i++)
	{
		if(distance[i] < shorest)
		{
			is_in  = T.find(i) != T.end();
			if(!is_in)
			{
				shorest = distance[i];
				next = i;	
			}

		}

	}
	T.insert(next);
	S.erase(next);	
	return 	next;
 }
 
 void S_P_Dijkstra::init(int start)
 {
 	for( int i=0; i< SIZE; i++)
 	{
 		if(i!=start)
 		{
 			distance.push_back(9999);
			S.insert(i);
		}
		else
		{
			distance.push_back(0);	
		}
		pre.push_back(-1);
	}
 }
 
void S_P_Dijkstra::outPut_d()
 {
 	gotoxy(S_P_Dijkstra::posx*20, S_P_Dijkstra::posy++);
 	printf("    d[v]");
 	gotoxy(S_P_Dijkstra::posx*20, S_P_Dijkstra::posy++);
 	for(int i=0; i< distance.size(); i++)
 	{
 		gotoxy(S_P_Dijkstra::posx*20, S_P_Dijkstra::posy++);
 		printf("%4d: %4d ", i,distance.at(i));
	}
 }
 
 void S_P_Dijkstra::outPut_pre()
 {
 	gotoxy(S_P_Dijkstra::posx*20, S_P_Dijkstra::posy++);
 	printf("    p[v]");
 	gotoxy(S_P_Dijkstra::posx*20, S_P_Dijkstra::posy++);
 	for(int i=0; i< pre.size(); i++)
 	{
 		gotoxy(S_P_Dijkstra::posx*20, S_P_Dijkstra::posy++);
 		printf("%4d: %4d ", i,pre.at(i));
	}
 }
 
 void S_P_Dijkstra::outPut_set()
 {
 	gotoxy(S_P_Dijkstra::posx*20, S_P_Dijkstra::posy++);
 	printf("  S ={ ");
 	for( auto s :T)
 	{
		printf("%d ",s); 
	}
	printf("}");
 }
 
 void S_P_Dijkstra::ouptPut_all(int iterator, int pos)
 {
 	
 	outPut_d();
 	
 	outPut_pre();
 
 	outPut_set();
 	gotoxy(S_P_Dijkstra::posx*20, S_P_Dijkstra::posy++);
 	printf("   step:%d",iterator);
 	S_P_Dijkstra::posy =0;
 }
 
 void S_P_Dijkstra::Dijkstra(int Start)
 {
 	int next, iter = 0;
 	init(Start);
	ouptPut_all(iter, S_P_Dijkstra::posx);
	S_P_Dijkstra::posx++;
	iter++;
 	while(!S.empty())
 	{
		next = find_min_cost();
		update_dist(next);
		ouptPut_all(iter, S_P_Dijkstra::posx);	
		iter++;
		S_P_Dijkstra::posx++;
	}
	
 }
 
 int **make_graph01()
 {
 	int adjacency_matrix[8][8] = {
	 								{0,0,0,0,0,0,0,0},
									{300,0,0,0,0,0,0,0},
									{1000,800,0,0,0,0,0,0},
									{0,0,1200,0,0,0,0,0},
									{0,0,0,1500,0,250,0,0},
									{0,0,0,1000,0,0,900,1400},
									{0,0,0,0,0,0,0,1000},
									{1700,0,0,0,0,0,0,0}
									};
	int **array = new int *[8];
	for(int i = 0; i <8; i++)
    	array[i] = new int[8];
    for(int i=0; i<8; i++)
    {
    	for(int j =0; j< 8; j++)
    	{
    		array[i][j] = adjacency_matrix[i][j];	;
		}
	}
	return array;

 }
 
 	
 int **make_graph02()
 {
 	int metrix01[9][9] = {
	 						{0,1,5,7,4,0,0,0,0},
							{0,0,0,0,0,3,10,0,0},
							{0,0,0,0,0,2,0,2,0},
							{0,0,0,0,0,0,1,0,0},
							{0,0,0,0,0,0,0,3,0},
							{0,0,0,0,0,0,0,0,2},
							{0,0,0,0,0,0,0,0,9},
							{0,0,0,0,0,0,0,0,5},
							{0,0,0,0,0,0,0,0,0}
							};
	int **array = new int *[9];
	for(int i = 0; i <9; i++)
    	array[i] = new int[9];
    for(int i=0; i<9; i++)
    {
    	for(int j =0; j< 9; j++)
    	{
    		array[i][j] = metrix01[i][j];		;
		}
	}
	return array;

 }
 
 int **make_graph03()
 {
 	int metrix01[8][8] = {
	 						{0,200,0,0,600,0,0,0},
							{0,0,700,250,300,0,0,0},
							{0,0,0,0,0,0,0,0},
							{0,0,1000,0,1500,0,100,150},
							{0,0,0,0,0,0,500,0},
							{2000,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0},
							{0,0,0,0,0,300,0,0},
							};
	int **array = new int *[8];
	for(int i = 0; i <8; i++)
    	array[i] = new int[8];
    for(int i=0; i<8; i++)
    {
    	for(int j =0; j< 8; j++)
    	{
    		array[i][j] = metrix01[i][j];		;
		}
	}
	return array;

 }							

 
 int main(){

	int **metrix_example = make_graph01();
	int **metrix_99 = make_graph02();
	int **metrix_88 = make_graph03();
//	S_P_Dijkstra graph(metrix_example, 8);					
//	graph.Dijkstra(4);
	
//	S_P_Dijkstra graph(metrix_99, 9);					
//	graph.Dijkstra(0);

	S_P_Dijkstra graph(metrix_88, 8);					
	graph.Dijkstra(0);

	system("PAUSE");
 }

