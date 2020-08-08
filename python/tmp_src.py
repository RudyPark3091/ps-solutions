a=[]
for i in range(1,10001):
    a.append(i+sum([int(j) for j in str(i)]))

l = list(set(range(10001)) - set(a))
l.sort()
for j in l:
    print(j)
