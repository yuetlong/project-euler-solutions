#!/usr/bin/env python3

def isPalindrome(n):
    return str(n) == str(n)[::-1]

def binary(n):
    return "{0:b}".format(n)

print(sum(i for i in range(1,1000000) if isPalindrome(str(i)) and isPalindrome(binary(i))))
