from math import gcd

def get_hcf(arr):
    hcf = arr[0] 
    for i in arr:
        hcf = gcd(hcf,i)
    return hcf

def lcm(a,b):
    return a*b//gcd(a,b)

def get_lcm(arr):
    l = arr[0] 
    for i in arr:
        l = lcm(l,i)
    return l

def getTotalX(a,b):
    lcm_a = get_lcm(a)
    hcf_b = get_hcf(b)
    no_between_sets = sum(1 for i in range(lcm_a, hcf_b+1, lcm_a) if not hcf_b%i and i%lcm_a==0)
    return no_between_sets
    
n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))



print(getTotalX(a,b))
