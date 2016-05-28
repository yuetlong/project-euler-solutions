#include <stdio.h>  // printf
#include <stdlib.h> // free
#include <string.h> // memset
typedef enum {false, true} bool;

/* is_prime_under() returns an array where arr[i] = true if i is a prime.
 * The array terminates with literal value -1.
 */

int* is_prime_under(int limit){
    int* arr = malloc ((limit + 1) * sizeof(int));
    arr[0] = arr[1] = false;
    memset((void*) arr, 1, sizeof(int) * (limit + 1));
    for (int i = 2; i * i < limit; i++)
        if(arr[i])
            for (int j = i * i; j < limit; j += i)
                arr[j] = false;
    arr[limit] = -1;
    return arr;
}

/* quick implementation of pow for integer.
 */

int int_pow(int x,int y){
    int x2 = 1;
    if (y == 0) return 1;
    while (y--){
        x2 *= x;
    }
    return x2;
}

/* check if a six digit integer has duplicates in the first five digits 
 */

bool has_duplicate_digits(int num){
    int digit_count[10] = {0};
    for (int n = 0; n < 5; n++){
        int nth_digit = num / int_pow(10, 5 - n) % 10;
        digit_count[nth_digit]++;
    }
    for (int i = 0; i < 10; i++)
        if (digit_count[i] > 1)
            return true;
    return false;
}

/* calculates the power set of an array, where in each subset of the outcome,
 * there is at least two items in it.
 * For instance, if arr[] = {1,2,3}
 * the function returns {2,1,2,2,1,3,2,2,3,3,1,2,3,-1}
 * The first number states the number of elements in the subset, followed by the elements.
 */

int* powerset_2plus(int* arr, int arr_size){
    // pow_set_size has the number of possible subsets in the power set
    unsigned int pow_set_size = int_pow(2,arr_size);
    
    //allocate space in heap for return. We are ommiting the empty set and subset with 1 element.
    int* powerset = malloc(sizeof(int) * (pow_set_size - arr_size));
    int* powerset_ptr1 = powerset + 1;
    int* powerset_ptr2 = powerset;

    for (int counter = 2; counter < pow_set_size; counter++){
        // if counter is NOT a power of 2, which means if counter doesn't have one bit on only
        if (counter & (counter - 1)){
            *powerset_ptr2 = 0;
            for (int j = 0; j < arr_size; j++){
                if(counter & (1 << j)){
                    *powerset_ptr1++ = arr[j];
                    (*powerset_ptr2)++;
                }
            }
            powerset_ptr2 = powerset_ptr1++;
        }
    }
    *powerset_ptr2 = -1;
    return powerset;
}
    
int replace_digit(int old_value, int n, int new_digit){
    int p = int_pow(10, 5 - n);
    int nth_value = old_value / p % 10 * p;
    int new_nth_value = int_pow(10, 5 - n) * new_digit;
    return old_value - nth_value + new_nth_value;
}

int main(){
    int set[]= {3,2,1};
    int* powerset = powerset_2plus(set, 3);
    while(*powerset != -1){
        printf("%d %p\n", *powerset, powerset);
        powerset++;
    }
}
