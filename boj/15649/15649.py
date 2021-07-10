n, m = map(int, input().split())

arr = [0 for _ in range(9)]
visited = [False for _ in range(9)]


def foo(cnt):
    if cnt == m:
        for i in range(m):
            print(arr[i], end=" ")
        print("")
        return

    for i in range(1, n+1):
        if not visited[i]:
            visited[i] = True
            arr[cnt] = i
            foo(cnt + 1)
            visited[i] = False


foo(0)
