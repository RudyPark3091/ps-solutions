import math

n = int(input())
p = math.ceil(n/2)

even = n%2 == 0
odd = n%2 == 1

for i in range(n):
    print("* " * (p-1) + "*")
    if even:
        print(" *" * (p))
    else:
        print(" *" * (p-1))
