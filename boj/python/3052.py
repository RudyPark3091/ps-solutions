l = []
rl = []
d = {}

for i in range(10):
    l.append(int(input()))

for item in l:
    rl.append(item%42)

for item in rl:
    d[item] = 0

print(len(d.keys()))
