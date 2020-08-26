import sys
n = int(sys.stdin.readline())
l = [0] * 10001

for i in range(n):
    input_val = int(sys.stdin.readline())

    l[input_val] += 1

for index, item in enumerate(l):
    if item:
        for i in range(item):
            print(index)
