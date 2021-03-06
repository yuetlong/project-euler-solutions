#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 1201

void decrypt(int b[], int i, int j, int k){
  int n = 0;
  while (n < SIZE){
    printf("%c", b[n++] ^ i);
    printf("%c", b[n++] ^ j);
    printf("%c", b[n++] ^ k);
  }
  printf("\n\n");
}

int main () {
    int buffer [SIZE];

    {
     FILE* stream;
     int size = 0;
     stream = fopen ("p059_cipher.txt", "r");
     while (fscanf (stream, "%d,", &buffer[size]) == 1)
       size++;
     fclose (stream);
    }

    for (int i = 97; i <= 122; i++){
      for (int j = 97; j <= 122; j++){
        for (int k = 97; k <= 122; k++){
          decrypt(buffer,i,j,k);
        }
      }
    }

    return 0;
}
