#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

int formula (int n, int a, int b){
  return (int) (pow(n,2) + a * n + b);
} 

int main(void){
  char* si;
  int a;
  int b;
  int max;
  int maxab;
  
  si = fill_prime_sieve(1000);
  max = -1;
  
  for (a = -999; a < 1000; ++a){
    for(b = -999; b < 1000; ++b){
      int n;
      n = 0;
      while (formula(n,a,b) > 1 && si[formula(n,a,b)] == 1)
	++n;
      if (n > max){
	max = n;
	maxab = a*b;
      }}}

  printf("%d\n",maxab);
  free(si);
  return 0;
}
