#include<stdio.h>

int * Make1DArrayBySize(unsigned int size)
{
    int *data = (int *)calloc(size, sizeof(int));
    return data;
}
int main()
{

}