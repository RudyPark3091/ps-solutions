n = int(input())
l = []

for i in range(n):
    l.append(list(map(int, input().split(' '))))

l.sort()
for item in l:
    print(str(item[0]) + ' ' + str(item[1]))
