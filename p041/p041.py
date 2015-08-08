#!/usr/bin/env python3

from sieve import Sieve
from itertools import permutations

answer = None
for i in range(4,8):
    si = Sieve(10 ** i)
    pandigitals = map(lambda x: int(''.join(x)), permutations(map(str, range(i, 0, -1))))
    answer = next(filter(si.isPrime, pandigitals), False)
print(answer)
