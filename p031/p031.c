#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,j;
  int coinSizes[8] = { 1, 2, 5, 10, 20, 50, 100, 200 };
  int *ways;

  ways = (int*) calloc(201, sizeof(int));
  ways[0] = 1;

  for (i = 0; i < 8; i++) 
    for (j = coinSizes[i]; j < 201; j++) 
      ways[j] += ways[j - coinSizes[i]];

  printf("%d\n", ways[200]);
  free(ways);
}
