#include<stdio.h>
<<<<<<< HEAD
#include <Windows.h>
=======
>>>>>>> a5ac59135ce4d70bf9c006a84b92c96638268d96
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
typedef unsigned char bool;
<<<<<<< HEAD
enum ConsoleTextColor{
                  CTC_GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
                  CTC_WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
				  };
=======
>>>>>>> a5ac59135ce4d70bf9c006a84b92c96638268d96

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

<<<<<<< HEAD
Myfile MCreateFile()
{
	char path[NMAX];
	printf("Please input file name:\n");
	fflush(stdin);
=======
Myfile CreateFile()
{
	char path[NMAX];
	printf("Please input file name:\n");
>>>>>>> a5ac59135ce4d70bf9c006a84b92c96638268d96
	scanf("%49[^\n]%*c", path);
	Myfile file = (Myfile)malloc(sizeof(file));
	if(!isFileExist(path))
	{
<<<<<<< HEAD
		printf("in create file path:%s\n", path);
=======
>>>>>>> a5ac59135ce4d70bf9c006a84b92c96638268d96
		strcpy(file->path , path);
		file->fileStream = fopen(path, "w");
	}
	else
		printf("file already exist");
	fclose(file->fileStream);
<<<<<<< HEAD
	fflush(stdin);
	return file;
}

void MWriteFile(Myfile source)
{   //到底為什不能直接使用sourc->bufer 並餵給fwrite???, 且連strpy也不能使用  
=======
	return file;
}

void WriteFile(Myfile source)
{   
>>>>>>> a5ac59135ce4d70bf9c006a84b92c96638268d96
	char buffer[CMAX];
	printf("Please input content:\n");
	fgets(buffer, CMAX, stdin);
	source->fileStream = fopen(source->path, "w+");	
	fwrite(buffer, 1, strlen(buffer), source->fileStream);
	fclose(source->fileStream);
<<<<<<< HEAD
	strcpy(source->ContentBuffer, buffer);
	printf("in MWriteFile source->ContentBuffer: %s\n in MWriteFile buffer: %s\n", source->ContentBuffer, buffer);
	printf("in Writefile source address %p\n", source);
	fflush(stdin); 
}
void AnalysicsFile(const char * source)
{

	unsigned short length = 0, token = 0, alpha = 0, number = 0, i = 0;
	bool isStriked = false;

	printf("content in source :%s\n", source);
	length = strlen(source);
	for(i; i< length; i++)
	{
		if((source)[i] == ' ')
		{
			if(!isStriked)
				token++;
			isStriked = true;
		}
		else
			isStriked = false;
		if(isalpha((source)[i]))
			alpha++;
		if(isdigit((source)[i]))
			number++;

	}
	printf(" length : %3d\n token: %3d\n alpha: %3d\n number: %3d\n", length, ++token, alpha, number);
	
}
char *trimwhitespace(char *str)
{
	unsigned short count = 0;
	char *temp = malloc(100*sizeof(char));
	char *end;
=======
	strcpy(source->ContentBuffer, buffer); 
}

char *trimwhitespace(char *str)
{
	char *end;
	char temp[CMAX];
	unsigned short count;
>>>>>>> a5ac59135ce4d70bf9c006a84b92c96638268d96
	while(isspace((unsigned char)*str)) str++;
	if(*str == 0) 
	return str;
	end = str + strlen(str) - 1;
	while(end > str && isspace((unsigned char)*end))
	{
		end--;
<<<<<<< HEAD
		count++;	
	} 

	end[1] = '\0';
	strncpy(temp, str, strlen(str)-count+1);
	return temp;
}

void MReadFile()
{
	char fileName[NMAX], fileContent[CMAX];
	printf("Please input file name:\n");
	fflush(stdin);
	scanf("%49[^\n]%*c", fileName);
	if(!isFileExist(fileName))
	{
		printf("Error opening file\n");
		return;
	}
	printf("file name u input:%s\n", fileName);
	FILE * fin = fopen(fileName, "r");
	fread(fileContent, 1, CMAX, fin);
	printf("read from file :%s\n", fileContent);
	printf("start analysics\n");
	AnalysicsFile(fileContent);
	
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
	Myfile sample ;
	unsigned short input;
//	bool isFirst = true;y

	while(true)
	{
		printf("1.Create file and input content\n2.Analysis the file u just input\n3.find substr\n4.exit\n");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				sample = MCreateFile();
				printf("after create before call MWriteFile source address %p\n", sample);
				printf("after create before call MWriteFile source  var address %p\n", &sample);
				MWriteFile(sample);
				printf("after MWriteFile source address %p\n", sample);
				break;
			case 2:
				MReadFile();
				break;
			case 3:
				if(sample)
				{
					char substr[CMAX];
					printf("input string u want find\n");
					fflush(stdin);
					fgets(substr, CMAX, stdin);
					findSubString(sample->ContentBuffer, substr);
				}
				else
					printf("u need to create a file first!!\n");
				break;
			case 4:
				return;
		}
	
	}
	return 0;

=======
		count++;
	} 
	strncpy(temp, str, strlen(str)-count);
	end[1] = '\0';
	return str;
}
void AnalysicsFile(Myfile source)
{
	unsigned short length, token, alpha, number, i = 0;
	bool isStriked = false;
	char temp[CMAX];
	strcpy(temp, source->ContentBuffer);
	trimwhitespace(temp);
	length = strlen(temp)-1;
	for(i; i< length; i++)
	{
		if((temp)[i] == ' ')
		{
			if(!isStriked)
				token++;
			isStriked = true;
		}
		else
			isStriked = false;
		if(isalpha((temp)[i]))
			alpha++;
		if(isdigit((temp)[i]))
			number++;

	}
	printf(" length : %3d\n token: %3d\n alpha: %3d\n number: %3d\n", length, ++token, --alpha, number);
}


int main()
{
>>>>>>> a5ac59135ce4d70bf9c006a84b92c96638268d96
//	Myfile f1 = CreateFile();
//	WriteFile(f1);
//	AnalysicsFile(f1);
	
<<<<<<< HEAD
//	char Rbuffer[50];
//	char *testbuffer = "Hello world haha!";
//	char *sub = "worl";
//	findSubString(testbuffer, sub);
	
	
=======
	char Rbuffer[50];
	char *testbuffer = "    abcde 123 2   ";
	printf("fasdfas");
>>>>>>> a5ac59135ce4d70bf9c006a84b92c96638268d96
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

<<<<<<< HEAD
=======
   
   
   
   
   return(0);
>>>>>>> a5ac59135ce4d70bf9c006a84b92c96638268d96
	
} 
