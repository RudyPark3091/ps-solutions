def solution(a):
    answer = 0
    able = []
    select = []
    l = a
    arr = [0 for _ in range(1000000)]
    visited = [False for _ in  range(1000000)]

    def get_two(idx, cnt, lst):
        if cnt == 2:
            select.append([arr[0], arr[1]])
            return

        for i in range(idx, len(lst)):
            if not visited[i]:
                visited[i] = True
                arr[cnt] = i
                get_two(i + 1, cnt + 1, lst)
                visited[i] = False

    get_two(0,0,a)
    for item in select:
        x = item[0]
        y = item[1]
        if l[x] < l[y]:
            l.remove(l[y])

    return answer

print(solution([9,-1,-5]))