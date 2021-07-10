a = int(input())
b = int(input())
c = int(input())

n = a * b * c
r = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
for i in str(n):
    r[int(i)] += 1

for item in r:
    print(item)
