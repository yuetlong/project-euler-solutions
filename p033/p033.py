#!/usr/bin/env python3

# Check out this solution
# http://www.mathblog.dk/project-euler-33-fractions-unorthodox-cancelling-method/

from fractions import Fraction

f = Fraction(1,1)

for i in range(1, 10):
    for d in range (1, i):
        for n in range (1, d):
            if d * (10 * n + i) == n * (10 * i + d):
                f *= Fraction(n,d)

print(f.denominator)
