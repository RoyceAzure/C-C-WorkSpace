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
typedef unsigned char bool;
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
	fflush(stdin);
	scanf("%49[^\n]%*c", path);
	Myfile file = (Myfile)malloc(sizeof(file));
	if(!isFileExist(path))
	{
		printf("in create file path:%s\n", path);
		strcpy(file->path , path);
		file->fileStream = fopen(path, "w");
	}
	else
		printf("file already exist");
	fclose(file->fileStream);
	fflush(stdin);
	return file;
}


void MWriteFile(Myfile source)
{   //�쩳�������ઽ���ϥ�sourc->bufer ������fwrite???, �B�sstrpy�]����ϥ�  
	char buffer[CMAX];
	printf("Please input content:\n");
	fgets(buffer, CMAX, stdin);
	source->fileStream = fopen(source->path, "w+");	
	fwrite(buffer, 1, strlen(buffer), source->fileStream);
	fclose(source->fileStream);
	strcpy(source->ContentBuffer, buffer);
	printf("in MWriteFile source->ContentBuffer: %s\n in MWriteFile buffer: %s\n", source->ContentBuffer, buffer);
	printf("in Writefile source address %p\n", source);
	fflush(stdin); 
}

void MReadFile()
{
	char fileName[NMAX], fileContent[CMAX];
	printf("Please input file name:\n");
	scanf("%49[^\n]%*c", fileName);
	if(!isFileExist)
	{
		printf("Error opening file\n");
		return;
	}
	printf("file name u input:%s\n", fileName);
	FILE * fin = fopen(fileName, "r");
	fread(fileContent, 1, CMAX, fin);
	printf("read from file :%s\n", fileContent);
	
}


int main()
{
	MReadFile();
}
