#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int* Tarray(char **target,int r1=0,int r2=0,int c1=0,int c2=0);
void Parray(char*);
int* setArray(char **);

int size;
int row;

int main(int argc,char *argv[]){
	size = argc-2;
	row = sqrt(size);
	int *result;
	
	Tarray(argv);
	Tarray(argv,1,4);
	Tarray(argv,1,1,2,3);
	return 0;
	
}
int* setArray(char **target){
	int *result = new int[size];
	for(int i=1 ; i<size+1; i++){
		*(result+i-1) =atoi(*(target+1+i));
//		printf("%3d",*(result+i-1));
//		 if(i%row==0 && i!=0)
//			printf("\n");
	}
	return result;
}



int* Tarray(char **target,int c1,int c2,int r1,int r2){
	int *Arow = new int[row];
	int *Acol = new int[row];
	int temp =0;
	for(int i=0; i<row; i++){
		*(Arow+i)=i;
		*(Acol+i)=i;
	}
	if(r1!=0 && r2 !=0){
		temp = *(Arow+r1-1);
		*(Arow+r1-1) = *(Arow+r2-1);
		*(Arow+r2-1) = temp;
	}
	
	if(c1!=0 && c2 !=0){
		temp = *(Acol+c1-1);
		*(Acol+c1-1) = *(Acol+c2-1);
		*(Acol+c2-1) = temp;
	}
	
//	for(int i=0; i<row; i++){
//		printf("%3d",*(Arow+i));
//	}
//	printf("\n");
//		for(int i=0; i<row; i++){
//		printf("%3d",*(Acol+i));
//	}
//	printf("\n");
//	printf("\n");
	int *result = setArray(target);  //result ok
	
	for(int i=0; i<row; i++){
		for(int j=0; j<row; j++){
			printf("%3d",result[Acol[j]+row*Arow[i]]);
		}
		printf("\n");
	}
	printf("\n");
}
