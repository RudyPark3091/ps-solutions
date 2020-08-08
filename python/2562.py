l = []

for i in range(9):
    l.append(int(input()))

m = max(l)
i = l.index(m) + 1
print(m)
print(i)
