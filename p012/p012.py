#!/usr/bin/env python

def divisors(n):
    j = 0
    for i in range (1,n/2 + 1):
        if n % i == 0:
            j += 1
    return j + 1
        
