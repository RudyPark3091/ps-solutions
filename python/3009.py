three = []

for i in range(3):
    three.append(list(map(int, input().split())))

if three[0][0] == three[1][0]:
    b = three[2][0]
elif three[0][0] == three[2][0]:
    b = three[1][0]
else:
    b = three[0][0]

if three[0][1] == three[1][1]:
    d = three[2][1]
elif three[0][1] == three[2][1]:
    d = three[1][1]
else:
    d = three[0][1]

print(b, d)
