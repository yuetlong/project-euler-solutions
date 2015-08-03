from math import factorial

ans = 0

for n in range(1,101):
    for r in range (1, n + 1):
        if factorial(n) / factorial(r) / factorial(n - r) > 1000000:
            ans += 1

print(ans)
