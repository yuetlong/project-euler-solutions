#include <stdio.h>

int main(void){
  int sum = 1;
  int spiral = 3;
  int step = 2;
  int number = 1;
  while (spiral < 1002){
    for (int i = 0; i < 4; i++){
      number += step;
      sum += number;
    }
    step += 2;
    spiral += 2;
  }
  printf("%d\n",sum);
}
