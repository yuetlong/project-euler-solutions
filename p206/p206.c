#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

bool hasForm(uint64_t n){
  if (n % 10)
    return false;
  n /= 100;
  for (short i = 9; i > 0; i--){
    if (!(n % 10 == i))
      return false;
    n /= 100;
  }
  return true;
}

int main(){
  for(uint64_t i = 1010101010; i <= 1389026624; i++){
    if (hasForm(i * i)){
      printf("%lld \n", i);
      return 0;
    }
  }
  printf("None was found.\n");
}
