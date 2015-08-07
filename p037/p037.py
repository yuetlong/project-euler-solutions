#!/usr/bin/env python3

from sieve import Sieve

def truncate(n):
    return list(int(str(n)[i:]) for i in range(len(str(n)))) + list(int(str(n)[:i]) for i in range(1, len(str(n))))

si = Sieve(1000000)
primes = si.getAllPrimes()[4:] # 2 3 5 7 are not considered to be truncatable primes
answer = sum (p for p in primes if all(map(si.isPrime, truncate(p))))
print(answer)
