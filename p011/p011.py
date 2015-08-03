#!/usr/bin/env python

from helper import file_to_string
grid = file_to_string('11_grid')
grid = grid.split("\n")

M = [[0 for p in range(20)] for q in range(20)] 

for i in range(20):
    tmp = grid[i].split(" ")
    for j in range(20):
        M[i][j] = int(tmp[j])

ans = 0

for i in range(17):
    for j in range(20):
        product = M[i][j] * M[i+1][j] * M[i+2][j] * M[i+3][j]
        if product > ans:
            ans = product

for i in range(20):
    for j in range(17):
        product = M[i][j] * M[i][j+1] * M[i][j+2] * M[i][j+3]
        if product > ans:
            ans = product

for i in range(17):
    for j in range(17):
        product = M[i][j] * M[i+1][j+1] * M[i+2][j+2] * M[i+3][j+3]
        if product > ans:
            ans = product

for i in range(17):
    for j in range(3,20):
        product = M[i][j] * M[i+1][j-1] * M[i+2][j-2] * M[i+3][j-3]
        if product > ans:
            ans = product

print ans
