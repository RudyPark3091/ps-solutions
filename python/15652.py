n, m = map(int, input().split())

arr = [0 for _ in range(8)]
visited = [False for _ in range(8)]


def foo(idx, cnt):
    if cnt == m:
        for i in range(m):
            print(arr[i], end=" ")
        print("")
        return

    for i in range(idx , n):
        arr[cnt] = i + 1
        foo(i, cnt + 1)


foo(0, 0)
