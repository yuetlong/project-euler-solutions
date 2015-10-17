#!/usr/bin/env python3

limit = 1000000



def truncate(n):

    # returns a list of n truncated from left and right

    l1 = list( int( str(n)[i:]) for i in range(   len(str(n))))
    l2 = list( int( str(n)[:i]) for i in range(1, len(str(n))))
    return l1 + l2

# sieve using array lookup

is_prime = [False] * 2 + [True] * (limit - 1)
for n in range (int(limit**0.5 + 1.5)):
	if is_prime[n]:
		for i in range (n * n, limit + 1, n):
			is_prime[i] = False

# prime generator

prime_generator = [i for i, prime in enumerate (is_prime) if prime]

# evaluate answer

answer = sum (p for p in prime_generator if all ( map (lambda x: is_prime[x], truncate(p))))
print(answer - 2 - 3 - 5 - 7)
