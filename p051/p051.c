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

bool has_duplicates_012(int num){
    bool hasDigit[3] = {false};
    // remember, we are not checking the last digit
    for (int n = 0; n < 5; n++){
        int nth_digit = num / int_pow(10, 5 - n) % 10;
        if (nth_digit < 3){
            if(hasDigit[nth_digit])
                return true;
            hasDigit[nth_digit] = true;
        }
    }
    return false;
}

/* calculates the power set of an array, where in each subset of the outcome,
 * there is at least two items in it.
 * The first number states the number of elements in the subset, followed by the number
 * of the elements. Followed by the elements themselves.
 */

void powerset_2plus(int* powerset, int arr[], int arr_size){
    // pow_set_size has the number of possible subsets in the power set
    int pow_set_size = int_pow(2,arr_size);
    
    //allocate space in heap for return. We are ommiting the empty set and subset with 1 element.
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
}


/* Returns a list of duplicated digits, what they are, and their positions.
 * The function ignored last digit. The return list ends with -1.
 */
int* duplicate_list(int num){
    int digit_count[10] = {0};
    int* lst = malloc(sizeof(int) * 128);
    int* ptr = lst;
    for (int i = 0; i < 5; i++){
        digit_count[num / int_pow(10,5-i) % 10]++;
    }
    for (int i = 0; i < 10; i++){
        if (digit_count[i] == 2){
            *ptr++ = i;
            *ptr++ = digit_count[i];
            for (int j = 0; j < 5; j++){
                if (num / int_pow(10, 5-j) % 10 == i){
                    *ptr++ = j;
                }
            }
        } else if (digit_count[i] > 2){
            int ptr2[digit_count[i]];
            int cnt = 0;;
            for (int j = 0; j < 5; j++){
                if (num / int_pow(10, 5-j) % 10 == i){
                    ptr2[cnt++] = j;
                }
            }
            int* ptr4 = malloc(sizeof(int) * 128);
            powerset_2plus(ptr4, ptr2, digit_count[i]);
            int* ptr4_start = ptr4;
            while(*ptr4 != -1){
                *ptr++ = i;
                *ptr++ = *ptr4++;
                for (int k = *(ptr4 - 1); k > 0; k--){
                    *ptr++ = *ptr4++;
                }
            }
            free(ptr4_start); 
        }
    }
    *ptr++ = -1;
    return lst;
}

int replace_digit(int old_value, int n, int new_digit){
    int p = int_pow(10, 5 - n);
    int nth_value = old_value / p % 10 * p;
    int new_nth_value = int_pow(10, 5 - n) * new_digit;
    return old_value - nth_value + new_nth_value;
}

int main(){
    
    int* sieve = is_prime_under(1000000);
    for (int i = 100000; i < 1000000; i++){
        if (sieve[i] && has_duplicates_012(i)){
            int* lst = duplicate_list(i);
            int* lst_ptr = lst;
            int cnt = 0;
            //printf("%d ", i);
            while(*lst != -1){
                int original_digit = *lst++;
                int original_number = i;
                int number_of_digits_to_replace = *lst++;
                int prime_counter = 1; // i itself is prime
                while(++original_digit < 10){  
                    for (int j = number_of_digits_to_replace ; j > 0; j--){
                        original_number = replace_digit(original_number, *lst++, original_digit);
                    }
                    lst -= number_of_digits_to_replace;
                    //printf("%d ", original_number);
                    if (sieve[original_number]){
                        prime_counter++;
                    } else {
                        continue;
                    }
                }
                if (prime_counter == 8){
                    printf("%d\n", i);
                    free(lst_ptr);
                    exit(0);
                }
                lst += number_of_digits_to_replace;
            }
            //printf("\n");
            free(lst_ptr);
        }
    }
    free(sieve);
}
