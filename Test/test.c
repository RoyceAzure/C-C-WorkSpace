#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./neuron.h"

int main(int argc, char *argv[]) {
    int prime = isPrime(3);
    printf("isPrime(%d) = %d\n", 3, prime);
    return 0;
}
