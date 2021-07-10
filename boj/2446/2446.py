n = int(input())

for i in range(n,0,-1):
    s = n - i
    p = 2*i - 1
    print(" " * s, end="")
    print("*" * p)

for i in range(1,n,1):
    print(" " * (n-i-1), end="")
    print("*" * (2*i + 1))
