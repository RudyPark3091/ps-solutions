t = int(input())
for i in range(t):
    h, w, n = map(int, input().split())
    r = 1

    while n - h > 0:
        n -= h
        r += 1
    room_num = str(r) if r >= 10 else '0' + str(r)
    print(str(n) + room_num)
