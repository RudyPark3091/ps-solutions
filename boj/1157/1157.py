s = input()
sl = list(s.lower())

c = {}
for item in sl:
    try:
        c[item] += 1
    except KeyError:
        c[item] = 1

v = c.values()
m = max(v)

a = []
for item in c.keys():
    if c[item] == m:
        a.append(item.upper())

if len(a) == 1:
    print(a[0])
else:
    print("?")
