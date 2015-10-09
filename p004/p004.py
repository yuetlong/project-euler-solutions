#!/usr/bin/env python

def is_palindrome(string):
    if len(string) == 0 or len(string) == 1:
        return True
    elif string[0] is string[-1]:
        return is_palindrome(string[1:-1])
    else:
        return False

answer = 0

for number1 in range(100,999):
    for number2 in range(100,999):
        contestant = number1 * number2
        if is_palindrome(str(contestant)) and contestant > answer:
            answer = contestant

print answer
