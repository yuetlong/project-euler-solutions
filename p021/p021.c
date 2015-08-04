#include <stdio.h>
#include <math.h>

int d(int n){
  int sum = 1;
    for (int i = 2; i < (int) sqrt(n) + 1; i++)
      if (!(n%i))
        sum += i + n/i;
    return sum;
}

int main(){
  int sum = 0;
  for (int a = 1; a < 10000; a++){
    int b = d(a);
    if (d(a) == b && d(b) == a && a != b)
      sum += a;
  }
  printf("%d\n",sum);
}
