int main()
{

	srand(time(NULL));
	tRegHead *L1 = (tRegHead*)calloc(1,sizeof(tRegHead));
	tRegHead *L2 = (tRegHead*)calloc(1,sizeof(tRegHead));
	tRegHead *L3 = (tRegHead*)calloc(1,sizeof(tRegHead));
//	for(int i=0; i<3; i++)
//		randomExtend(L1);
	printList(L1);
	
	
	while(true)
	{
		insert(L1);
//	insert(L1);
		printList(L1);
	}
	
//	
//	Rem(L1,5);
//	printList(L1);
//	
//	printf("Sort!!\n");
//	Bsort(L1);
//	printList(L1);
	
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
	int data,mode;
	unsigned short pos;
	printf("Enter a data you want to insert:");
	scanf("%d",&data);
	printf("Enter a pos you want to insert:");
	while(!(scanf("%d",&pos) == 1 && 1<=pos && pos <= p->counts+1 ))
	{
		fflush(stdin);
		printf("Enter correct pos:");
	}
	printf("(1)front (2)rear");
	scanf("%d",&mode);	
	tReg *newNode = (tReg*)calloc(1,sizeof(tReg));
	newNode->data = data;    
	tReg *current = p->front;
//------------init-------------------	

	if( p->counts == 0)
	{
		p->front = p->rear = newNode;
	}
	else if( pos == 1 && mode == 1)
	{
		newNode->next = current;
		current->prev = p->front = newNode;
	}
	else if((pos == p->counts && mode == 2) || pos == p->counts+1)
	{
		newNode->prev = p->rear;
		p->rear = p->rear->next = newNode;
	}
	else
	{
		for(int i=0; i<pos-1; i++)
		{
			current = current->next;
		}
		if(mode == 1)
		{
			newNode->next = current;
			newNode->prev = current->prev;
			current->prev = current->prev->next = newNode;
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
	printf("\n\n");
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
