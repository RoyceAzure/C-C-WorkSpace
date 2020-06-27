#ifndef ARRAY1D_H
#define ARRAY1D_H
#include<stdio.h>
#include<stdlib.h>
int * Make1DArrayBySize(unsigned int size)
{
    int *data = (int *)calloc(size, sizeof(int));
    return data;
}

#endif