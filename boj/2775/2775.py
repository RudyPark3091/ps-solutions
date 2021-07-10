t = int(input())

lst = [[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]]

for i in range(14):
    sl = [1]
    for j in range(2, 15):
        sl.append(sum(lst[i][0:j]))
    lst.append(sl)

for i in range(t):
    k = int(input())
    n = int(input())
    print(lst[k][n-1])
