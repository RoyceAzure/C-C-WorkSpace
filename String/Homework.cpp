#include<stdio.h>
#include <Windows.h>
#include<string.h>
#define CMAX 9999
#define NMAX 20
#define true 1
#define false 0
typedef struct file 
{
	char path[NMAX];
	FILE *fileStream;
	unsigned short token, alpha, length, letter, number;
	char ContentBuffer[CMAX]; 
}file;
typedef file *Myfile;
//typedef unsigned char bool;
enum ConsoleTextColor{
                  CTC_GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
                  CTC_WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
				  };

bool isFileExist(const char * path)
{
	FILE *ptr = fopen(path,"r");
	if(ptr)
	{
		fclose(ptr);
		return true;
	}
//	fclose(ptr);
	return false;
}

Myfile MCreateFile()
{
	char path[NMAX];
	printf("Please input file name:\n");
	scanf("%49[^\n]%*c", path);
	Myfile file = (Myfile)malloc(sizeof(file));
	if(!isFileExist(path))
	{
		strcpy(file->path , path);
		file->fileStream = fopen(path, "w");
	}
	else
		printf("file already exist");
	fclose(file->fileStream);
	return file;
}

void MWriteFile(Myfile source)
{   //到底為什不能直接使用sourc->bufer 並餵給fwrite???, 且連strpy也不能使用  
	char buffer[CMAX];
	printf("Please input content:\n");
	fgets(buffer, CMAX, stdin);
	source->fileStream = fopen(source->path, "w+");	
	fwrite(buffer, 1, strlen(buffer), source->fileStream);
	fclose(source->fileStream);
	strcpy(source->ContentBuffer, buffer); 
}

char *trimwhitespace(char *str)
{
	unsigned short count = 0;
	char *temp = malloc(100*sizeof(char));
	char *end;
	while(isspace((unsigned char)*str)) str++;
	if(*str == 0) 
	return str;
	end = str + strlen(str) - 1;
	while(end > str && isspace((unsigned char)*end))
	{
		end--;
		count++;	
	} 

	end[1] = '\0';
	strncpy(temp, str, strlen(str)-count+1);
	return temp;
}
void AnalysicsFile(Myfile source)
{
	unsigned short length = 0, token = 0, alpha = 0, number = 0, i = 0;
	bool isStriked = false;
	trimwhitespace(source->ContentBuffer);
	length = strlen(source->ContentBuffer);
	for(i; i< length; i++)
	{
		if((source->ContentBuffer)[i] == ' ')
		{
			if(!isStriked)
				token++;
			isStriked = true;
		}
		else
			isStriked = false;
		if(isalpha((source->ContentBuffer)[i]))
			alpha++;
		if(isdigit((source->ContentBuffer)[i]))
			number++;

	}
	printf(" length : %3d\n token: %3d\n alpha: %3d\n number: %3d\n", length, ++token, alpha, number);
	
}

void setConsoleColor(enum ConsoleTextColor textColor)
{
    //STD_ERROR_HANDLE;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, textColor);
}

void findSubString(const char *fullstr, const char *substr)
{
	char *temp = NULL;
	bool isFind = false, isFirst = true;
	int i = 0, j = 0, pos = -1, countFind = 0;
	printf("substr u type is :%s\n", substr);
	while((unsigned char *)fullstr != '\0' && !isFind)
	{
		if(fullstr[i] == substr[j])
		{
			if(isFirst)
			{
				pos = i;
				isFirst = !isFirst;	
			}
			j++;
		}
		else
		{
			isFirst = true;
			j = 0;
			pos = -1;
		}
		if(j == strlen(substr)-1)
		{
			isFind = true;
			countFind++;
			j = 0;
		}
			
		i++;
	}
	if(isFind)
	{
		printf("find pos = %d\n substr len = %d\n", pos, strlen(substr));
		int k = 0;
		for(k ;k < strlen(fullstr); k++)
			if(k>=pos && k<=(pos+strlen(substr)-1))
			{
				setConsoleColor(CTC_GREEN);
				printf("%c", fullstr[k]);
			}
			else
			{
				setConsoleColor(CTC_WHITE);
				printf("%c", fullstr[k]);
			}		
	}
	else
	{
		printf("not found!\n");
	}
}



int main()
{
	Myfile sample = NULL;
	int input;
	printf("1.Create file and input content\n2.Analysis the file u just input\n3.find substr\n4.exit\n");
	while(scanf("%d", &input)==1 || input!=4)
	{
		switch(input)
		{
			case 1:
				sample = MCreateFile();
				MWriteFile(sample);
				break;
			case 2:
				if(sample)
					AnalysicsFile(sample);
				else
					printf("u need to create a file first!!\n");
				break;
			case 3:
				if(sample)
				{
					char substr[CMAX];
					printf("input string u want find\n");
					fgets(substr, CMAX, stdin);
					findSubString(sample->ContentBuffer, substr);
				}
				else
					printf("u need to create a file first!!\n");
				break;
			case 4:
				return;
		}
		return 0;
	}
	
	
	
	
	
//	Myfile f1 = CreateFile();
//	WriteFile(f1);
//	AnalysicsFile(f1);
	
//	char Rbuffer[50];
	char *testbuffer = "Hello world haha!";
	char *sub = "worl";
	findSubString(testbuffer, sub);
	
	
//	printf("\n %s\n", trimwhitespace(testbuffer));
//	FILE *test = fopen("test2.txt","w+");
//	fwrite(testbuffer, 1, 5, test);
//	fclose(test);
//	if(test)
//	{
//		
//		printf("ptr exists\n");
//		size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
//		fseek(test, 0, SEEK_SET);
//		fread(Rbuffer, strlen(testbuffer)+1, 1, test);
//		printf("%d \n:", strlen(Rbuffer));
//		printf("read from file %s :", Rbuffer);
//	} 
//		
//	else 
//		printf("ptr not exists");

   
   
   
   
   return(0);
	
} 
