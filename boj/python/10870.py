n = int(input())
seriesArr = [0,1]

def series(number, first, second):
    if number == n:
        print(seriesArr[n])
        return

    temp = first
    first = second
    second = temp + second
    seriesArr.append(second)

    series(number+1, first, second)

if n == 0:
    print(0)
else:
    series(1, 0, 1)
