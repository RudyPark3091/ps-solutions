n, m = map(int, input().split())

arr = [0 for _ in range(8)]
visited = [False for _ in range(8)]


def foo(cnt):
    if cnt == m:
        for i in range(m):
            print(arr[i], end=" ")
        print("")
        return

    for i in range(1, n+1):
        arr[cnt] = i
        foo(cnt + 1)


foo(0)
