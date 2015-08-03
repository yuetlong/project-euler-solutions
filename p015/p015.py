#!/usr/bin/env python3

A = [[0 for i in range(21)] for j in range(21)]

for i in range(1,21):
    A[i][0] = 1
    A[0][i] = 1

for i in range(1,21):
    for j in range (1,21):
        A[i][j] = A[i-1][j] + A[i][j-1]

print(A[20][20])
