#!/usr/bin/env python3

import itertools

def primes_upto(limit):
    is_prime = [False] * 2 + [True] * (limit - 1)
    for n in range (int (limit ** 0.5 + 1.5)):
        if is_prime[n]:
            for i in range(n * n, limit + 1 , n):
                is_prime[i] = False
    return is_prime

def all_rotations(n):
    if (n < 10):
        return [n]
    lst = [n]
    length = len(str(n))
    for i in range(length - 1):
        n = n % 10 * 10 ** (length - 1) + n // 10
        lst.append(n)
    return lst

sieve = primes_upto(1000000)
counter = 0

for i in range(1000000):
    lst = all_rotations(i)
    if all(map(lambda x: sieve[x], lst)):
        counter += 1
print(counter)
