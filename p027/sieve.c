#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

char* fill_prime_sieve(size_t limit)
{
  size_t i, j;

  char *sieve;

  sieve = malloc( sizeof(char) * limit);
  
  sieve[0] = sieve[1] = 0;

  memset(sieve, 1, limit);

  for(i = 2; i < limit; i++)
    {
      if(sieve[i] == 0) continue;

      for( j = i * i; j < limit; j+= i)
	{
	  sieve[j] = 0;
	}
    }

  return sieve;
}
