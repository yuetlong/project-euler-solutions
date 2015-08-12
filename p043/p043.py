#!/usr/bin/env python3
from itertools import permutations

pandigitals = map(''.join, permutations(map(str, range(10)))) # in strings

def hasProperty(n):
    primes = [2,3,5,7,11,13,17]
    for i in range(7):
        if int(n[i + 1: i + 4]) % primes[i] != 0:
            return False
    return True

answer = sum(map(int, filter(hasProperty,pandigitals)))
print(answer)
