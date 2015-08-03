#!/usr/bin/env python

def f1(n):
    a = 0
    for i in range (1,n+1):
        a += i**2
    return a

def f2(n):
    a = 0
    for i in range (1,n+1):
        a += i
    return a**2

print f2(100)-f1(100)
