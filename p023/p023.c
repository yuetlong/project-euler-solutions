#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_abundant(int n);

int is_abundant(int n){
  int sum = 1;
  int upbound = (int) floor(sqrt(n)) + 1;
  int i;
  for (i = 2;i < upbound; i++)
    if (!(n%i)){
      sum += i;
      if (i != n/i)
        sum += n/i;
    }
  return (sum > n);
}

int main(void){
  int i;
  int j;
  int answer = 0;
  int size = 0;
  int *abundant;
  _Bool *two_abundant_numbers;

  abundant = malloc(sizeof(int));
   /* find all abundant numbers from 12 to 28123 */
  for (i = 12; i < 28124; i++)
    if (is_abundant( i )){
     abundant[size++] = i;
     abundant = realloc(abundant, ((size_t)size + 1) * sizeof(int));
    }

  /* initialize all elements in two_abundant_numbers with 0 */
  two_abundant_numbers = calloc(29000, sizeof(_Bool));

  /* find all distinct sums of two abundant numbers */
  for (i = 0; i < size; i++){
    for(j = i; j < size; j++){
      int n3 = abundant[i] + abundant[j];
      if (n3 > 28123)
        break;
      two_abundant_numbers[n3] = 1;
    }
  }

  /* sum the answer */
  answer = 0;
  for (i = 1; i < 28124; i++)
    if(two_abundant_numbers[i] == 0)
      answer += i;
  printf("%d\n", answer);

  /* free allocated memory */
  free(two_abundant_numbers);
  free(abundant);

  return 0;
}
