n = int(input())
l = []

for i in range(n):
    l.append(input())

for item in l:
    if len(item) > 10:
        print(item[0] + str(len(item[1:-1])) + item[-1])
    else:
        print(item)

