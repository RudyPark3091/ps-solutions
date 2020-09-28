def solution(n):
    answer = []
    state = 0
    x = 0
    y = 0
    num = 1
    cnt = 0
    arr = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(n, 0, -1):
        for j in range(i):
            if state == 0:
                arr[x][y] = num
                num += 1
                if not j == i - 1:
                    x += 1
                else:
                    y += 1
                    state = (state + 1) % 3
            elif state == 1:
                arr[x][y] = num
                num += 1
                if not j == i - 1:
                    y += 1
                else:
                    x -= 1
                    y -= 1
                    state = (state + 1) % 3
            elif state == 2:
                arr[x][y] = num
                num += 1
                if not j == i - 1:
                    x -= 1
                    y -= 1
                else:
                    x += 1
                    state = (state + 1) % 3
                    
    for item in arr:
        for letter in item:
            if letter != 0:
                answer.append(letter)

    return answer
