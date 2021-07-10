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
        if not visited[i]:
            visited[i] = True
            arr[cnt] = i + 1
            foo(i+1, cnt + 1)
            visited[i] = False


foo(0, 0)
