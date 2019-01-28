#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5
typedef struct  circlar_quene{
    int *data;
    int front,rear;
    int size;
    int flag ;
    void init()
    {
        size = flag = 0;
        front = rear =0;
        data = (int*)calloc(1,sizeof(int) * MAX );
    }

    bool isEmpty()
    {
        if(front == rear && flag == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if(front == rear && flag == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Push()
    {
        if(isFull())
        {
            printf("Quene is FULL!!\n");
            return; 
        }
        else
        {
        	int temp = rand()%100 + 1;
        	printf("Push %d into ring\n",temp);
//        	scanf("%d",data + rear);
			*(data + rear) = temp;
        	rear = (rear + 1) % MAX;
        	size++;
        	flag = 1;
        }
    }
    void Pop()
    {
        if(isEmpty())
        {
            printf("Quene is Empty!!");
            return;
        }
        else
        {
            printf("Pop %d from ring\n",*( data + front ));
            front = (front +1) % MAX ;
            size--;
            flag = 0;
        }
    }
    int Len()
    {
        return size;
    }
    void printQuene()
    {
    	if(isEmpty())
    	{
    		printf("Print Failled, Ring is empty!!");
		}
		else
		{
			printf("data in ring: ");
			int index = front;
			for(int i=0; i<size; i++)
			{
				printf("%d ",*(data +index));
				index = (index+1) % MAX;
			}
		}
    	
        printf("\n");
    }
}C_que;


int main()
{
	srand(time(NULL));
    C_que C1;
    C1.init();
    int temp;
//    for(int i =0; i< 10;i++)
//    {
//        temp = rand() % 2 + 0;
//        switch (temp)
//        {
//        	case 0:
//        		C1.Pop();
//        		break;
//        	case 1:
//        		C1.Push();
//		}
//		C1.printQuene();
//    }
	for(int i=0; i<5 ;i++)
	{
		C1.Push();	
	}
	C1.printQuene();
   	for(int i=0; i<4 ;i++)
	{
		C1.Pop();	
	}
   	C1.printQuene();
   	C1.Push();
   	C1.Push();
   	C1.printQuene();
    return 0;
}

