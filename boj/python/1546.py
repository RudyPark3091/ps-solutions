n = int(input())

s = list(map(int, input().split(' ')))
m = max(s)
l = []

for item in s:
    l.append(item/m*100)

print(sum(l)/len(l))
