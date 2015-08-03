#!/usr/bin/env python3

A = ["" for i in range(1001)]

A[1] = "one"
A[2] = "two"
A[3] = "three"
A[4] = "four"
A[5] = "five"
A[6] = "six"
A[7] = "seven"
A[8] = "eight"
A[9] = "nine"
A[10] = "ten"
A[11] = "eleven"
A[12] = "twelve"
A[13] = "thirteen"
A[14] = "fourteen"
A[15] = "fifteen"
A[16] = "sixteen"
A[17] = "seventeen"
A[18] = "eighteen"
A[19] = "nineteen"
A[20] = "twenty"
A[30] = "thirty"
A[40] = "forty"
A[50] = "fifty"
A[60] = "sixty"
A[70] = "seventy"
A[80] = "eighty"
A[90] = "ninety"
A[1000] = "one thousand"

# We deal with 21 to 100 using 1-9,20,30,40,50,60,70,80,90.
for i in range (21, 100):
    A[i] = A[i - i % 10] + " " +  A[i % 10]

for i in range (100, 999, 100):
    A[i] = A[i // 100] + " hundred"

for i in (i for i in range (101, 1000) if i % 100):
    A[i] = A[i // 100 * 100] + " and " + A[i % 100]

for index,item in enumerate(A):
    print(index,item)

answer = 0
for word in A:
    answer += len(word) - word.count(' ')
    
print(answer)
