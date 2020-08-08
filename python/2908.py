a, b = map(int, input().split(" "))
ast = str(a)
bst = str(b)

ap = ""
bp = ""

for i in range(len(ast)):
    ap += str(ast[-i-1])

for i in range(len(bst)):
    bp += str(bst[-i-1])

if int(ap) > int(bp):
    print(ap)
else:
    print(bp)
