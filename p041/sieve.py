#!/usr/bin/env python3
import numpy as np
from bisect import bisect_left

class Sieve(object):
    primes = None

    def __init__(self, n):
        sieve = np.ones(n/3 + (n%6==2), dtype=np.bool)
        sieve[0] = False
        for i in range(int(n ** 0.5)//3 + 1):
            if sieve[i]:
                k=3*i+1|1
                sieve[      ((k*k)/3)      ::2*k] = False
                sieve[(k*k+4*k-2*k*(i&1))/3::2*k] = False
        self.primes = np.r_[2,3,((3*np.nonzero(sieve)[0]+1)|1)]

    def isPrime(self, n):
        if n < 2:
            return False
        elif n == 2:
            return True
        elif not n % 2:
            return False

        i = bisect_left(self.primes, n)
        if i != len(self.primes) and self.primes[i] == n:
            return True
        return False

    def getAllPrimes(self):
        return self.primes
