n = int(input())


def fib(num):
    if num == 0:
        return 0
    elif num == 1:
        return 1
    else:
        i = 0
        j = 1
        for id in range(num-1):
            f = i + j
            i = j
            j = f
        return f


print(fib(n))
