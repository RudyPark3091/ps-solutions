l = []


def d(n: int):
    r = 0
    if n>10000:
        return None
    else:
        r += n
        for letter in str(n):
            r += int(letter)
        return r


for i in range(1, 10001):
    l.append(d(i))

lst = list(set(range(1, 10001)) - set(l))
lst.sort()

for item in lst:
    print(item)
