n = int(input())

row = [0 for _ in range(n)]
cnt = 0

def check_yrow(y):
    global cnt
    if y == n:
        cnt += 1
        return

    for i in range(n):
        flag = True
        for j in range(y):
            if row[j] == i or (abs(y-j) == abs(i-row[j])):
                flag = False
                break
    
        if flag:
            row[y] = i
            check_yrow(y+1)


check_yrow(0)
print(cnt)
