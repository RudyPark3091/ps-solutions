l = [True] * 10000


def d(n: int):
    r = 0
    if n>10000:
        return None
    else:
        r += n
        for letter in str(n):
            r += int(letter)
        return r


def t(index, list):
    if index > 10000:
        return
    else:
        if d(index) >= 10000:
            pass
        else:
            list[d(index)] = False
        t(d(index), list)


for i in range(1, 10001):
    t(i, l)

for i in range(1, 10000):
    if l[i]:
        print(i)
