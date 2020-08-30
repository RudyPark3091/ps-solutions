x, y, w, h = map(int, input().split())

for i in range(max(w,h)):
    if x + i == w:
        print(i)
        break
    if y + i == h:
        print(i)
        break
    if x - i == 0:
        print(i)
        break
    if y - i == 0:
        print(i)
        break
