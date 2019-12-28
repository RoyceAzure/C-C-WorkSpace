#include<stdio.h>
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

Myfile CreateFile()
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

void WriteFile(Myfile source)
{   
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
	char *end;
	char temp[CMAX];
	unsigned short count;
	while(isspace((unsigned char)*str)) str++;
	if(*str == 0) 
	return str;
	end = str + strlen(str) - 1;
	while(end > str && isspace((unsigned char)*end))
	{
		end--;
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
//	Myfile f1 = CreateFile();
//	WriteFile(f1);
//	AnalysicsFile(f1);
	
	char Rbuffer[50];
	char *testbuffer = "    abcde 123 2   ";
	printf("fasdfas");
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
