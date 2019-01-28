#include<stdlib.h>
#include<stdio.h>
#include<time.h>

typedef struct Reg{
	int data;
	struct Reg *prev,*next;
}tReg;


typedef struct RegHead{
	int counts;
	tReg *front,*rear;
}tRegHead;


int ReSetLen(tRegHead*);
void insert(tRegHead*);
void printList(tRegHead*);
void randomExtend(tRegHead*);
void Rem(tRegHead*,int);
bool isEmpty(tRegHead*);
void Bsort(tRegHead*);

int main()
{
	tRegHead *L1 = (tRegHead*)calloc(1,sizeof(tRegHead));
	tRegHead *L2 = (tRegHead*)calloc(1,sizeof(tRegHead));
	for(int i=0; i<5; i++)
		randomExtend(L1);
	printList(L1);
	
	
	insert(L1);
	printList(L1);
	
	Rem(L1,5);
	printList(L1);
	
	printf("Sort!!\n");
	Bsort(L1);
	printList(L1);
	
	return 0;
	
}




void Bsort(tRegHead*p)
{
	bool swap = true;
	tReg *current;
	for(int i =p->counts; i>1 && swap == true ; i--)
	{
		swap = false;
		current = p->front;
		for(int j=1; j<i ;j++)
		{
			if(current->data > current->next->data)
			{
				int temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				swap = true;
			}
			current = current->next;
		}
	}
}



bool isEmpty(tRegHead* p)
{
	return p->front==NULL;
}
void Rem(tRegHead*p,int pos)
{
	
	if(isEmpty(p))
	{
		printf("Empty Link!!\n");
		return;
	}
	tReg *current = p->front;
	if(pos<0)
	{
		printf("Out of Bound!!\n");
	}
	else
	{
		for(int i =1; i<pos &&current ; i++)
		{
			current = current->next	;
		}
		if(!current)
		{
			printf("Out of Bound!!\n");
			return;
		}
		else if(current==p->front)
		{
			p->front->next->prev = NULL;
			p->front = p->front->next;
			
		}
		else if(current == p->rear)
		{
			p->rear->prev->next = NULL;
			p->rear = p->rear->prev;
			
		}
		else
		{
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}
		free(current);
		p->counts--;
	}
}




int ReSetLen(tRegHead* p)
{
	int length =0;
	tReg *current = p->front;
	while(current)
	{
		length++;
		current = current->next;
	}
	return length;
}

void insert(tRegHead* p)
{
	int data,posttion,mode;
	
	printf("Enter a data you want to insert:");
	scanf("%d",&data);
	printf("Enter  insert pos:");
	scanf("%d",&posttion);
	printf("(1)front (2)rear");
	scanf("%d",&mode);
	
	
	tReg *current = p->front;
	for(int i =1; i<posttion && current ; i++)
	{
		current = current->next; 
	}
	if(current)
	{
		tReg *newNode = (tReg*)calloc(1,sizeof(tReg)); 
		newNode->data = data;
		if(mode==1)  //insert front
		{
			if(current == p->front)  //insert head
			{
				newNode->next = p->front;
				p->front = p->front->prev = newNode;
			}
			else
			{
				newNode->next = current;
				newNode->prev = current->prev;
				current->prev = current->prev->next = newNode;
			}
		}
		else   //intert rear
		{
			if(current == p->rear)
			{
				p->rear->next = newNode;
				p->rear = newNode;
			}
			else
			{
				newNode->next = current->next;
				newNode->prev = current;
				current->next = current->next->prev = newNode;
			}
		}
		p->counts++;
	}
	else
	{
		printf("Out of Bound!!\n");
	}
	
} 


void printList(tRegHead* p)
{
	tReg *current = p->front;
	printf("Counts: %d\n",p->counts);
	printf("From head: ");
	while(current)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
	current = p->rear;
	printf("From rear: ");
	while(current)
	{
		printf("%d ",current->data);
		current = current->prev;
	}
	printf("\n");
}

void randomExtend(tRegHead* p)
{
	tReg *newNode = (tReg *)calloc(1,sizeof(tReg));
	newNode->data = rand()% 100 +1;
	
	if(p->front)
	{
		newNode->prev = p->rear;
		p->rear = p->rear->next = newNode;
	}
	else
	{
		p->rear = p->front = newNode; 
	}
	p->counts++;
} 


