n = input()
if int(n) < 10:
    n = '0' + n

c = 0

n2 = n
while True:
    if n2 == '00':
        n2 = '0'
    elif n2[0] == '0':
        n2 = n2[1]

    if int(n2) < 10:
        n2 = '0' + n2

    nf = str(int(n2[0]) + int(n2[1]))
    if int(nf) < 10:
        nf = '0' + nf

    if n2 == n and c != 0:
        print(c)
        break
    else:
        n2 = n2[1] + nf[1]
        c += 1
