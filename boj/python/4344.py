c = int(input())
l = []

for i in range(c):
    l = list(map(int, input().split(' ')))
    n = l[0]
    l2 = l[1:len(l)]
    avg = sum(l2)/len(l2)
    i = 0
    for item in l2:
        if item > avg:
            i += 1
    print(str('%.3f' % (i/len(l2)*100)) + '%')
