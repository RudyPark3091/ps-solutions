t = int(input())

for i in range(t):
    n = int(input())
    d = {}
    for j in range(n):
        name = input().split()[1]
        if name in d.keys():
            d[name] += 1
        else:
            d[name] = 1

    res = 1
    for num in d.values():
        res *= num+1
    print(res - 1)
