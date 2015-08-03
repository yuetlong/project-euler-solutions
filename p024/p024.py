#!/usr/bin/env python3
from itertools import permutations, islice

it = permutations('0123456789',10)
val = next (islice (it,999999, None),None)
print (val)
