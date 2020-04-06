#include<iostream>
#include "Queue.h"
using namespace std;

template<typename T, int M, int N>
void BFS(const T (&Graph)[M][N], int start)
{
	int visited[7] = {0};
	int i =start;
    printf(" excute visited %d\t", start);    
	visited[i] = 1;
	enqueue(i);
	while(!isEmpty())
	{
		i = dequeue();
		for(int j = 1; j < N; j++)
		{
			if(Graph[i][j] == 1 && visited[j] == 0)
			{
				printf(" excute visited %d\t", j);
				visited[j]=1;
				enqueue(j);
			}
		}
	
	}
}

template<typename T, int M, int N>
void DFS(const T (&G)[M][N], int start)
{
	static int visited[7] = {0};
	int j;
	if(visited[start] == 0)
	{
		printf("excute visited %d\t", start);
		visited[start] = 1;
		for(j = 1; j< N; j++)
		{
			if(G[start][j] == 1 && visited[j] == 0)
					DFS(G,j);
		}
	}
}

int main()
{
	cout<< "test" << "\n";
	int G[7][7]={{0,0,0,0,0,0,0},
			 	{0,0,1,1,0,0,0},
			  	{0,1,0,0,1,0,0},
			   	{0,1,0,0,1,0,0},
			    {0,0,1,1,0,1,1},
				{0,0,0,0,1,0,0},
				{0,0,0,0,1,0,0}};
	BFS(G,2);
	printf("\n");
	DFS(G,2);
	return 0;
}
