#include <stdio.h>
#include <math.h>

static double array[10000];
static int l = 0;

void add(double n){
  for (int c= 0; c < l; c++)
    if(n == array[c])
      return;
  array[l++] = n;
}

int main(void){
  for (int a = 2; a < 101; a++)
    for (int b = 2; b < 101; b++)
      add(pow(a,b));
  printf("%d\n",l);
}
