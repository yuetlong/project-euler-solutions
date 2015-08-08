#!/usr/bin/env python3

def solu(p):
    count = 0
    for a in range(1, p - 1): # upper bound include solution {p - 2, 1 , 1}
        for b in range(a, p - a): # {a, p - a - 1, 1}:
            c = p - a - b
            if a ** 2 + b ** 2 == c ** 2:
                count += 1
    return count
answer = max(((p, solu(p)) for p in range (2,1000,2)), key = lambda x: x[1])
print(answer[0])
