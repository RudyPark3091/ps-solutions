import sys

mylist = []
while True:
    mylist.append(sys.stdin.readlines())
    if len(mylist) > 4:
        break

h = mylist[0:3]
b = mylist[3:4]

min = 10000
for burger in h:
    for drink in b:
        if (burger + drink) < min:
            min = burger + drink

print(min - 50)