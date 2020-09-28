def solution(n):
    total = sum(range(1, n+1))
    answer = [0 for _ in range(total)]

    # cnt = 0
    # for i in range(n):
    #     answer[cnt + i] = i+1
    #     cnt += i
    # for i in range(n-1):
    #     answer[sum(range(1,n)) + i+1] = n + i + 1

    # val = 2 * n
    # idx = total - n - 1
    # for i in range(n-1, 1, -1):
    #     answer[idx] = val
    #     val += 1
    #     idx -= i

    # for i in range(n-2, n):
    #     idx += i
    #     answer[idx] = val
    #     val += 1


    def foo(cnt, num):
        if cnt == n:
            return
        if cnt % 3 == 0:
            idx = sum(range(cnt + 1))
            for i in range(n - cnt):
                answer[idx + i] = num + i + 1
                idx += i
                if i == n - cnt:
                    foo(cnt + 1, i)

        elif cnt % 3 == 1:
            idx = sum(range(n - cnt//3 - 1)) + 1
            for i in range(n - cnt - 1):
                answer[]

        else:
            pass


    foo(0, 0)

    return answer

print(solution(6))