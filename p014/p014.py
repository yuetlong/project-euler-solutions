#!/usr/bin/env python3

import numpy as np

def iter(n):
    def helper(m,n):
        if not n ^ 1: # XNOR checks if n equals 1.
            return m
        elif n & 1: # AND checks if n is odd
            return helper(m + 1, n*3 + 1)
        else: # n is even
            return helper(m + 1, int(n/2))
    return helper(0,n)


index = np.argmax([iter(i) for i in range(1,1000000)])

print (index + 1) # evaluation started at 1.
