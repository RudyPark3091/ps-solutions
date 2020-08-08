# n = int(input())
n = 27

li = []
for i in range(n):
    li.append(list("*" * n))


def make_hole(p, np, nptwo, myList):
    if p == 1:
        return

    m = int(p/3)
    dnp = int(np/3)
    dnptwo = int(nptwo/3)

    while np+m < n:
        for i in range(np, np + m):
            for j in range(nptwo, nptwo + m):
                myList[i][j] = ' '
        np += m

    make_hole(m, int(np/3), int(nptwo/3), myList)



make_hole(n, int(n/3), int(n/3), li)

result = []
for item in li:
    string = ""
    for index in item:
        string += index
    result.append(string)

for item in result:
    print(item)
