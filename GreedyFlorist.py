#!/bin/python3

import sys

n, k = map(int,input().split())
c = list(map(int, input().split()))
cost=0
if n<k:
    print(sum(c[0:n]))
else:
    w = sorted(c,reverse=True)
    i = 0
    while(len(w) > 0):
        cost += sum(w[0:k])*(i+1)
        i += 1
        w = w[k:n]
    print(cost)
