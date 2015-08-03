#!/usr/bin/env python3
from collections import Counter

def isPandigital(m,n):
    return Counter(str(m)+ str(n)+ str(m * n)) == Counter("123456789")

products = set()

for i in range(1,10000):
    min = 10 ** (4 - len(str(i)))
    max = 10 ** (5 - len(str(i)))
    for j in range (min,max):
        if isPandigital(i,j) and i*j not in products:
           products.add(i * j)

print(products)
print(sum(products))
