import sys

n = int(sys.stdin.readline())
l = []

for i in range(n):
    l.append(tuple(map(int, sys.stdin.readline().split(' '))))

l = sorted(l, key=lambda l: (l[1], l[0]))

for item in l:
    print(item[0], item[1])
