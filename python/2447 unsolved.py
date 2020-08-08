# n = int(input())
n = 81

li = []
for i in range(n):
    li.append(list("*" * n))


def make_hole(p, np, nptwo, myList):
    if p == 1:
        return

    m = int(p/3)
    dm = int(m/3)
    dnp = int(np/3)
    dnptwo = int(nptwo/3)


    for i in range(dnp, dnp+dm):
        for j in range(dnptwo, dnptwo+dm):
            myList[i][j] = ' '

    for i in range(dnp, dnp+dm):
        for j in range(dnptwo+m, dnptwo+m+dm):
            myList[i][j] = ' '

    for i in range(dnp, dnp+dm):
        for j in range(dnptwo+2*m, dnptwo+2*m+dm):
            myList[i][j] = ' '

    for i in range(dnp+m, dnp+m+dm):
        for j in range(dnptwo, dnptwo+dm):
            myList[i][j] = ' '

    for i in range(np, np + m):
        for j in range(nptwo, nptwo + m):
            myList[i][j] = ' '

    for i in range(dnp+m, dnp+m + dm):
        for j in range(dnptwo+2*m, dnptwo+2*m + dm):
            myList[i][j] = ' '

    for i in range(dnp+2*m, dnp+2*m + dm):
        for j in range(dnptwo, dnptwo + dm):
            myList[i][j] = ' '

    for i in range(dnp+2*m, dnp+2*m + dm):
        for j in range(dnptwo+m, dnptwo+m + dm):
            myList[i][j] = ' '

    for i in range(dnp+2*m, dnp+2*m + dm):
        for j in range(dnptwo+2*m, dnptwo+2*m + dm):
            myList[i][j] = ' '


make_hole(n, int(n/3), int(n/3), li)

result = []
for item in li:
    string = ""
    for index in item:
        string += index
    result.append(string)

for item in result:
    print(item)
