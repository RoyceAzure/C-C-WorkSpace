#include <stdio.h>
#include <stdlib.h>
#include<string.h>

    struct Student_Perosnal_Data {
        char name[10];
        int age;
        char address[50];
        char interest[11];
        struct Student_Perosnal_Data* next;
    };

//
//    struct  {
//        char name[10];
//        int age;
//        char address[50];
//        char interest[11];
//        struct Student_Perosnal_Data* next;
//    }test;

	enum kind  
	{
		IF,
		LPAREN,
		ID,
		INTLIT
	};



int main()
{

    kind k = IF;
    printf("%d", k);
//    test.age = 10;
//    printf("%d", test.age);
    struct Student_Perosnal_Data stu;
    struct Student_Perosnal_Data stu1;
    strcpy(stu.name,"張三");
//    stu.next = (Student_Perosnal_Data*)malloc(sizeof(Student_Perosnal_Data));
    
    stu.next = &stu1;
    strcpy(stu.address, "南投縣埔里鎮大學路一號");
    strcpy(stu.interest, "basketball");
    stu1.age = 30;
    printf("The student's name is: %d\n", stu.next->age);
    printf("The student's age is: %d\n", stu.age);
    printf("The student's address is: %s\n", stu.address);
    printf("The student's interest is: %s\n", stu.interest);
	
	
} 
