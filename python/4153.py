while True:
    l = list(map(int, input().split()))

    m = max(l)
    mi = l.index(m)

    if l == [0, 0, 0]:
        break

    if l[mi] ** 2 == l[(mi+1)%3] ** 2 + l[(mi+2)%3] ** 2:
        print('right')
    else:
        print('wrong')
