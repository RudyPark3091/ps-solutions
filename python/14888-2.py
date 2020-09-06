minimum = 1000000001
maximum = -1000000001

def foo(cnt, num):
    global maximum, minimum
    global n
    if cnt == n:
        if maximum < num: maximum = num
        if minimum > num: minimum = num
        return

    if ops[0]:
        ops[0] -= 1
        foo(cnt + 1, num + arr[cnt])
        ops[0] += 1
    if ops[1]:
        ops[1] -=1
        foo(cnt + 1, num - arr[cnt])
        ops[1] += 1
    if ops[2]:
        ops[2] -=1
        foo(cnt + 1, num * arr[cnt])
        ops[2] += 1
    if ops[3]:
        ops[3] -=1
        if num < 0: foo(cnt + 1, -(-num//arr[cnt]))
        else: foo(cnt + 1, num // arr[cnt])
        ops[3] += 1
    return


n = int(input())
arr = list(map(int, input().split()))
ops = list(map(int, input().split()))

foo(1, arr[0])

print(maximum)
print(minimum)
