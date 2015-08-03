#include <stdio.h>
#include <math.h>

int fit(int n, int j){
  int s, p;
  p = n;
  s = 0;
  while(n){
    s += (int) pow(n % 10, j);
    n /= 10;
  }
  return (s == p);
}

int main(void){
  int i;
  int sum = 0;
  for (i = 10; i < 10000000 ; ++i)
    if(fit( i , 5))
      sum += i;

  printf("%d\n",sum);
  return 0;
}
