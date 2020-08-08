n = int(input())

c5 = n // 5
r = n % 5
c3 = r // 3


if n < 10 and n != 5 and n != 8:
    print(-1 if n % 3 != 0 else n//3)
else:
    if n == 12:
        print(4)
    else:
        if r % 3 == 0:
            print(c5 + c3)
        elif r % 3 == 1:
            if c5 > 1:
                c5 = c5 - 1
                print(c5 + c3 + 2)
            else:
                print(-1)
        elif r % 3 == 2:
            if c5 > 2:
                c5 = c5 - 2
                print(c5 + c3 + 4)
            else:
                print(-1)
