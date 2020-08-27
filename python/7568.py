n = int(input())
whlist = []
for i in range(n):
    whlist.append(list(map(int,input().split())))

for item in whlist:
    counter = 1
    for item_two in whlist:
        if item[0] < item_two[0] and item[1] < item_two[1]:
            counter += 1
    print(counter, end=" ")
