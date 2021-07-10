targetNum = int(input())

series = 1
n = 1

# 1, 7, 19, 37, 61 ...

while targetNum > series:
    series += 6 * n
    n += 1

print(1 if targetNum == 1 else n)
