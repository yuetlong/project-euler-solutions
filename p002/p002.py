#!/usr/bin/env python3
def fib_gen(maxnum):
    n1,n2 = 1,1
    while n1 <= maxnum:
        yield n1
        n1,n2 = n1+n2,n1
        
print(sum(filter(lambda x: x%2==0,fib_gen(4000000))))
