#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(void){
  mpz_t n1;
  mpz_t n2;
  char* str;
  unsigned int index;
  size_t length;

  mpz_inits (n1,n2);

  mpz_set_ui(n1, 1);
  mpz_set_ui(n2, 1);

  index = 1;
  length = 0;

  do{
    mpz_add(n2, n1, n2);
    mpz_sub(n1, n2, n1);

    str = mpz_get_str(NULL, 10, n1);
    length = strlen(str);
    free(str);

    index ++;
  }
  while(length != 1000);

  printf("%d\n", index);

  mpz_clear(n1);
  mpz_clear(n2);

  return 0;
}
