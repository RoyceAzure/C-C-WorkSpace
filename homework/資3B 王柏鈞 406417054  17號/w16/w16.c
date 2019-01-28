#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef unsigned char bool;
typedef unsigned int uInt32;



typedef struct stuff_mem{
	char name_[20];
	bool type_;
	union 
	{
		char moble_number_[20];
		char tel_number_[20];
	}phoneNumber;
	enum company {
			CHT = 1,
			FET,
			TWN
		}CMP;
	struct stuff_mem *next;
	struct stuff_mem *prev;
}Stuff;


typedef struct member
{
	uInt32 counts;
	Stuff *head;

}Member_list;



Stuff * add_to_memberlist(Member_list *list)
{
	Stuff *newStuff = (Stuff*)malloc(sizeof(Stuff));
	printf("Please input stuff name:\n");
	scanf("%s", newStuff->name_);
	newStuff->next = NULL;
	newStuff->prev = NULL;
	char number[20];
	
	while(1)
	{
		printf("Please input Phone type(1) Moble (2) Tel:\n");
		scanf("%d", &newStuff->type_);
		if( newStuff->type_ ==1 | newStuff->type_ ==2)
		{
			break;
		}
	}
	

	if( newStuff->type_== 1 )
	{
		bool type;
		printf("Please input Phone CMP(1)CHT (2)FET (3)TWN:\n");
		scanf("%d", &type);
		if(type == 1)
		{
			newStuff->CMP = CHT;
		}
		else if(type == 2)
		{
			newStuff->CMP = FET;
		}
		else if(type == 3)
		{
			newStuff->CMP = TWN;
		}
		printf("Please input moble phone number:\n");
		scanf("%s", newStuff->phoneNumber.moble_number_);
	}
	else
	{
		printf("Please input telephone number:\n");
		scanf("%s", newStuff->phoneNumber.tel_number_);
	}
	if(list->counts ==0)
	{
		list->head = newStuff;
	}
	else
	{
		uInt32 i;
		uInt32 count = list->counts;
		Stuff *current= list->head;
		for( i =0; i<count-1;i++)
		{
			current = current->next;
		}
		newStuff->prev = current;
		current->next = newStuff;
	}
	list->counts++;
	
	return newStuff;
}

void printList(Member_list *list)
{
	Stuff *current = list->head;
	while(current)
	{
		if(current->type_ == 1)
		{
			char *CMP;
			switch(current->CMP)
			{
				case 1:
					CMP = "CHT";
					break;
				case 2:
					CMP = "FET";
					break;	
				case 3:
					CMP = "TWN";
					break;
			}
			printf(" name: %s, phone number :%s, CMP : %s",current->name_, current->phoneNumber, CMP);	
		}
		else
		{
			char areaNum[2];
			strncpy(areaNum, current->phoneNumber.tel_number_, 2);
			printf(" name: %s, phone area number :%s phone number: %s",current->name_, areaNum, current->phoneNumber);
		}
		printf("\n");
		current = current->next;
	}

	
}


bool my_strcmp(const char *chr1, const char* chr2)
{
	if(chr1 == NULL || chr2 == NULL)
	{
		return 0;
	}
	
	while(*chr1 !='\0')
	{
		if((int)(*chr1) < (int)(*chr2))
		{
			return 1;
		}
		else if((int)(*chr1) > (int)(*chr2))
		{
			return 255;
		}
		chr1++;
		chr2++;
	}
	return 0;
}

void sort_member_list(Member_list *list)
{
	uInt32 i,j;
	bool result;
	uInt32 count = list->counts;
	Stuff *current ;
	for(i=count-1; i>0; i--)
	{
		current = list->head;
		for(j=0; j<i; j++)
		{
			result = (my_strcmp(current->name_, current->next->name_));
			if(result ==255)
			{
				Stuff *temp = current->next;
				if(j == 0)
				{
					current->prev = temp;
					current->next = temp->next;
					temp->next->prev = current;
					temp->next = current;
					temp->prev = NULL;
					list->head = temp;
				}
				else
				{
					current->next = temp->next;
					temp->prev = current->prev;
					temp->next = current;
					current->prev->next = temp;
					current->prev = temp;
					
				}
				
			}
			else
			{
				current = current->next;
			}
		
		}
	}
}


int main()
{	
	uInt32 number,i;
	Member_list *list1 =(Member_list *) calloc(sizeof(Member_list),1);
	list1->counts =0;
	list1->head = NULL;
	printf("Please input number of stuff:\n");
	scanf("%d", &number);
	for(i = 0; i<number; i++)
	{
		add_to_memberlist(list1);
	}
	
	printList(list1);
	sort_member_list(list1);
	printList(list1);

	


	return 0;
}
