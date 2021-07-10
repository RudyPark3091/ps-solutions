# this method    occurs timeout

import operator
import math

n = int(input())
number_list = list(map(int, input().split()))
t = number_list[0]

ops_parsed = []
ops_list = list(map(int, input().split()))
ops_parsed = list('0' * ops_list[0])
ops_parsed += list('1' * ops_list[1])
ops_parsed += list('2' * ops_list[2])
ops_parsed += list('3' * ops_list[3])

arr = ['_'] * (n-1)
visited = [False] * n
res_max = -10000000001
res_min = 10000000001


def divideCpp(a, b):
    if a < 0:
        return -(-a//b)
    else:
        return a//b


ops = {'0': operator.add, '1': operator.sub, '2': operator.mul, '3': divideCpp}


def foo(cnt):
    global res_max
    global res_min
    if cnt == n-1:
        for i in range(1, n):
            number_list[0] = ops[arr[i-1]](number_list[0], number_list[i])
        if res_max < number_list[0]:
            res_max = number_list[0]
        elif res_min > number_list[0]:
            res_min = number_list[0]
        number_list[0] = t
        return
        
    for i in range(n-1):
        if not visited[i]:
            visited[i] = True
            arr[cnt] = ops_parsed[i]
            foo(cnt + 1)
            visited[i] = False


foo(0)
print(res_max, res_min, sep="\n")
