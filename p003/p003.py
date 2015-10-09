#!/usr/bin/env python
import math

def isprime(num):
    if (num < 2):
        return False
    elif (num == 2):
        return True
    elif (num % 2 == 0):
        return False
    else:
        for i in xrange(2, my_sqrt(num) + 1):
            if (num % i) == 0:
                return False
        return True

def my_sqrt(num):
    return int(round(math.sqrt(num)))

def largest_prime_factor(num):
    factor = my_sqrt(num)
    while factor > 1:
        if isprime(factor) and (num % factor == 0):
            return factor
        factor -= 1
    return "not found"

print largest_prime_factor(13195)
print largest_prime_factor(600851475143)
