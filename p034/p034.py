#!/usr/bin/env python3

from math import factorial

answer = 0

for i in range (10,100000):
    if sum(map(factorial, map(int, str(i)))) == i:
        answer += i

print(answer)
