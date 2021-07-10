n = int(input())
l = []
r = 0

for i in range(n):
    l.append(input())

for item in l:
    ll = []
    for i in range(len(item)):
        letter = item[i]
        if letter not in ll:
            ll.append(letter)
        else:
            if letter == item[i-1]:
                ll.append(letter)
                continue
            else:
                break
    if len(ll) == len(item):
        r += 1

print(r)
