#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {false, true} bool;
#define SIEVE_SIZE 1000000

void gen_sieve(int* sieve, int upper_bound){
    memset((void *) sieve, 1, sizeof(int) * upper_bound);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i < upper_bound; i++)
        if (sieve[i])
            for (int j = i * i; j < upper_bound; j += i)
                sieve[j] = false;
}

int first_digit_value(int x){
    int y = 1;
    while (x > 9){
        x /= 10;
        y *= 10;
    }
    return x * y;
}

bool is_truncatable_prime(int* sieve, int n){
    int n2 = n;
    do if (!sieve[n2]) return false;
    while (n2 /= 10); 
    n2 = n;
    while (n2 -= first_digit_value(n2))
        if (!sieve[n2]) return false;
    return true;
}

int main(){
    int* sieve = malloc(SIEVE_SIZE * sizeof(int));
    gen_sieve(sieve, SIEVE_SIZE);
    int count = 0, contestent = 11, sum = 0;
    while (count != 11){
        if (is_truncatable_prime(sieve, contestent)){
            sum += contestent;
            count++;
        }
        contestent++;
    }
    free(sieve);
    printf("%d\n", sum);
}
