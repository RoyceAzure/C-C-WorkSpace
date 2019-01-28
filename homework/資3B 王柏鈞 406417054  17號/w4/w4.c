#include<stdio.h>
#include<stdlib.h>

#define getName(var)  #var 
typedef struct num_list
{
    int counts;
    int *pList;
}tNumList;

void creat_lsit(tNumList *list);
void print_list(tNumList *list);
void bubbleSort(tNumList *list);
void merge (tNumList *list1, tNumList *list2);


void creat_lsit(tNumList *list)
{
	int number; 
	int i ;
	printf("Please enter how many numbers in %s :", getName(list));
	scanf("%d", &number);
	list->counts = number;
	list->pList = (int *)malloc(sizeof(int)*number);
	for(i = 0; i < number; i++)
	{
		scanf("%d", list->pList+i);
	}
	printf("\n");
}

void print_list(tNumList *list)
{
	int i=0;
	for(i; i<list->counts; i++)
	{
		printf("%d ", *(list->pList+i));
	}
	printf("\n");
}
void bubbleSort (tNumList *list)
{
  	int i, j, flag;
  	for(i = list->counts -1; i>0 ; i--)
	{ 
		int flag = 0;
	    for(j = 0; j < i; j++)
		{
	   		if(*(list->pList+j) > *(list->pList+j+1))
			{
				int temp = *(list->pList+j+1);
				*(list->pList+j+1) = *(list->pList+j);
				*(list->pList+j) = temp;
	        	flag = 1;
	      	}
	    }
	    if(flag == 0) break; 
	}
}
	


void merge (tNumList *list1, tNumList *list2)
{
	int i;
	int total = list1->counts + list2->counts;
	int *p1 = list1 ->pList;
	int *p2 = list2 ->pList;
	int *newList = (int*)malloc(sizeof(int) * total);
	
	for(i = 0; i<total ; i++ )
	{
			if( i >= list1->counts)
			{
				*(newList+i) = *(p2 + i-list1->counts );
			}
			else
			{
				*(newList+i) = *(p1 + i);
			}			
	}
	free(list1->pList);
	free(list2->pList);
	list1->pList = newList;
	list1->counts = total;
	
}


int main()
{
	tNumList *list1 = (tNumList *)malloc(sizeof(tNumList));
	tNumList *list2 = (tNumList *)malloc(sizeof(tNumList));
	creat_lsit(list1);
	creat_lsit(list2);
	
	bubbleSort(list1);
	bubbleSort(list2);
	printf("sort list1: ");
	print_list(list1);
	printf("sort list2: ");
	print_list(list2);
	printf("merge list: ");
	merge(list1, list2);
	print_list(list1);
	return 0;
}

