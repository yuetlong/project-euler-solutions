#!/usr/bin/env python3

import itertools

def primes_upto(limit):
    is_prime = [False] * 2 + [True] * (limit - 1)
    for n in range (int (limit ** 0.5 + 1.5)):
        if is_prime[n]:
            for i in range(n * n, limit + 1 , n):
                is_prime[i] = False
    return is_prime

def int_permu(n):
    digits = [int(x) for x in str(n)]
    length = len(digits)
    power  = length - 1
    perm   = itertools.permutations(digits)
    return (sum (v * (10 ** (power - i)) for i, v in enumerate(item)) for item in perm)

def is_circular_prime(n):
    return all(map(lambda x: sieve[x], int_permu(n)))

sieve = primes_upto(1000000)

print(list(filter(lambda x: sieve[x] == False, int_permu(19937))))

counter = 1
"""Counted two"""

for i in range(3,1000,2):
    if is_circular_prime(i):
        counter += 1

print(counter)
