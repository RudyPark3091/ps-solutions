n = int(input())
r = 0


def hs(pn):
    ns = str(pn)
    if pn < 100:
        return 1
    d = int(ns[0]) - int(ns[1])
    if pn > 99:
        if int(ns[1]) - int(ns[2]) == d:
            return 1
        else:
            return 0

print(sum(list(map(hs, range(1, n+1)))))
