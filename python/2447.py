n = int(input())
l = [['*'] * n for i in range(n)]


def star(lst, size, offsetx, offsety):
    if size == 1:
        return

    innerx1 = offsetx + size//3
    innerx2 = offsetx + 2 * size//3
    innery1 = offsety + size//3
    innery2 = offsety + 2 * size//3

    for i in range(innerx1, innerx2):
        for j in range(innery1, innery2):
            lst[i][j] = ' '

    star(lst, size//3, offsetx, offsety)
    star(lst, size//3, innerx1, offsety)
    star(lst, size//3, innerx2, offsety)
    star(lst, size//3, offsetx, innery1)
    star(lst, size//3, innerx1, innery1)
    star(lst, size//3, innerx2, innery1)
    star(lst, size//3, offsetx, innery2)
    star(lst, size//3, innerx1, innery2)
    star(lst, size//3, innerx2, innery2)



star(l, n, 0, 0)

for item in l:
    print(''.join(item))
