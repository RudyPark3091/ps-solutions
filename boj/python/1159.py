n = int(input())
d = {}
l = []

for i in range(n):
    s = input()
    try:
        d[s[0]] += 1
    except KeyError:
        d[s[0]] = 1

for item in d.items():
    if item[1] >= 5:
        l.append(item[0])

if len(l) == 0:
    print('PREDAJA')
else:
    l.sort(key=str.lower)
    for item in l:
        print(item, end='')

