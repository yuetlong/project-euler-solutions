#!/usr/bin/env python3
A = []
text = open ('18.txt','r')
for line in text:
    A.append(list(map(int,line.rstrip().split(' '))))
text.close()

for i in reversed(range(len(A) - 1)):
    for j in range(len(A[i])):
        A[i][j] += max(A[i+1][j], A[i+1][j+1])

print(A[0][0])
