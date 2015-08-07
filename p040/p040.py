#!/usr/bin/env python3

from functools import reduce

string = ''.join(list(map(str, range(190000))))

targets = [1,10,100,1000,10000,100000,1000000]

answer = reduce(lambda x, y: x * int(string[y]), targets, 1)

print(answer)
