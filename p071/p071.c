#include <stdio.h>

int gcd_iter (int u, int v){
  int t;
  while (v){
    t = u;
    u = v;
    v = t % v;
  }
  return u < 0 ? -u : u;
}

int main(){
  int d = 1000000;
  printf("%d\n", (int) ((float) d) / 7 * 3);
  while(gcd_iter(d, (int) ((float) d) / 7 * 3) != 1){
      d--;
    }
  printf("%d\n",d);
}
