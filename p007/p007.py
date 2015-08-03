#!/usr/bin/env python

from helper import is_prime

def f(n):
    j = 1
    while n > 0: # evaluation stops when nth prime was found
        j += 1
        while is_prime(j) == False:
            j += 1
        n -= 1
    return j

for k in range (1,7):
    print f(k)
    
print f(10001)
