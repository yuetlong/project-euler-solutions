#!/usr/bin/env python3

ans = 0
text = open ("p013.txt",'r')
for line in text:
    ans += int(line)
print(ans)
