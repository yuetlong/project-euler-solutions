#!/usr/bin/env python

for a in range ( 1 , 1001 ):
    for b in range ( a+1 , 1001-a ):
        for c in range (b+1 ,1001-a-b):
            if a**2 + b**2 == c**2 and a+b+c==1000:
                print a*b*c
