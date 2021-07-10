n = int(input())
ns = []
d = {}
mfv = []    # 최빈값의 값
maxv = 0    # 최빈값 빈도수

for i in range(n):
    m = int(input())
    ns.append(m)
ns.sort()

for item in ns:
    try:
        d[item] += 1
    except KeyError:
        d[item] = 1

for k, v in d.items():
    if maxv <= v:
        if maxv == v:
            mfv.append(k)
            maxv = v
        else:
            mfv = [k]
            maxv = v

print(round(sum(ns) / len(ns)))
print(ns[len(ns)//2])
try:
    print(mfv[1])
except IndexError:
    print(mfv[0])
print(ns[len(ns)-1] - ns[0])
