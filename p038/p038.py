#!/usr/bin/env python

def isPandigital(n): #didn't filter out false positives but it worked
    return sorted(str(concat_product(n))) == list("123456789")

def concat_product(n):
    return int(''.join((str(n * i) for i in range(1, 6)))[:9])

answer = max(concat_product(n) for n in range(9, 10000) if isPandigital(n))

print(answer)
