#ifndef NEURON_H
#define NEURON_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

int isPrime(int n); 
int isPrime(int n) {

  // returns 0 if not prime, 1 if prime

  if (n<2) return 0;         // first prime number is 2
  if (n==2) return 1;        // ensure 2 is identified as a prime
  if ((n % 2)==0) return 0;  // all even numbers above 2 are not prime

  int i;
  for (i=3; i*i < n; i++) {  // test divisibility up to sqrt(n)
    if ((n % i) == 0) {
      return 0;
    }
  }
  return 1;
}
#endif