#!/usr/bin/env python3
from functools import reduce
text = open ('p042_words.txt','r')
words = map(lambda x: x.strip("\""),next(text).split(','))
text.close()

scores = map(lambda x: reduce(lambda y,z: y + ord(z) - 64, x, 0), words)
def isTriangleNumber(n):
    a = 1
    b = 1
    c = -2 * n
    d = b ** 2 - 4 * a * c
    if (d < 0):
        return False
    s1 = (-b + d ** 0.5) / (2 * a)
    s2 = (-b - d ** 0.5) / (2 * a)
    if (s1 > 0 and s1%1 == 0) or (s2 > 0 and s2%1 == 0):
        return True
    return False

answer = sum(1 for i in filter(isTriangleNumber,scores))
print(answer)
