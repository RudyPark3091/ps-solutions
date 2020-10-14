import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
queue = deque()
for i in range(n):
    cmd = input()
    if cmd[0:2] == 'pu':
        queue.append(int(cmd[5:]))
    elif cmd[0:2] == 'po':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue.popleft())
    elif cmd[0:2] == 'si':
        print(len(queue))
    elif cmd[0:2] == 'em':
        if len(queue) == 0:
            print(1)
        else:
            print(0)
    elif cmd[0:2] == 'fr':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])
    elif cmd[0:2] == 'ba':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[-1])

