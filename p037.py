#!/usr/bin/env python3

def primes_upto(limit):
    is_prime = [False] * 2 + [True] * (limit - 1)
    for n in range (int (limit ** 0.5 + 1.5)):
        if is_prime[n]:
            for i in range(n * n, limit + 1 , n):
                is_prime[i] = False
    return is_prime

sieve = primes_upto(1000000)
