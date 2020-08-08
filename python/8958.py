n = int(input())
l = []
r = 0
rl = []

for i in range(n):
    l.append(input())

for item in l:
    i = 1
    for letter in item:
        if letter == 'O':
            r += i
            i += 1
        else:
            i = 1
    rl.append(r)
    r = 0

for item in rl:
    print(item)
