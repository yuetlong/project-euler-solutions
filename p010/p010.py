#!/usr/bin/env python

from helper import is_prime

i = 3
sum = 2

while i < 2000000:
    if is_prime(i):
        sum += i
    i += 2
    
print sum
