#!/usr/bin/env python3
from miller_rabin import is_probable_prime

def truncate(n):
    l1 = list( int( str(n)[i:]) for i in range(   len(str(n))))
    l2 = list( int( str(n)[:i]) for i in range(1, len(str(n))))
    return l1 + l2

def sieve(n):
    multiples = set()
    for i in range(2, n+1):
        if i not in multiples:
            yield i
            multiples.update(range(i*i, n+1, i))

si = sieve(1000000)
answer = sum (p for p in si if all ( map (is_probable_prime, truncate(p))))
print(answer - 2 - 3 - 5 - 7)
