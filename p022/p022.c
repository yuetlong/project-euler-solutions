#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *stream;
  stream = fopen("text-files/p022_names.txt","r");
  int size = 0;
  char buffer[6000][20];

  while (fscanf (stream, "\"%[A-Z]\",", buffer[size++]) == 1){};
  fclose(stream);

  qsort(buffer,size,20,strcmp);

  int namescore[size];
  int sum = 0;

  for(int i = 0; i < size; i++){
    namescore[i] = 0;
    for (int j = 0; j < strlen(buffer[i]); j++)
      namescore[i] +=  buffer[i][j] - 64;
    sum += namescore[i] * i;
  }

  printf("%d\n",sum);
}
