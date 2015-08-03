#!/usr/bin/env python3

from scipy.misc import factorial

val = factorial(100, exact = True)

def sum_digits(n):
    r = 0
    while n:
        r, n = r + n % 10, n//10
    return r

print(sum_digits(val))
