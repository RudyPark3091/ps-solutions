import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
cmd = ''
dq = deque()

for i in range(n):
    cmd = input()
    if cmd[0:2] == 'pu':
        if cmd[5] == 'b':
            dq.append(int(cmd[10:]))
        else:
            dq.appendleft(int(cmd[10:]))
    
    elif cmd[0:2] == 'po':
        if len(dq) == 0:
            print(-1)
        elif cmd[4] == 'b':
            print(dq.pop())
        else:
            print(dq.popleft())

    elif cmd[0:2] == 'si':
        print(len(dq))

    elif cmd[0:2] == 'em':
        print(1 if len(dq) == 0 else 0)

    elif cmd[0:2] == 'fr':
        print(dq[0] if len(dq) != 0 else -1)

    elif cmd[0:2] == 'ba':
        print(dq[-1] if len(dq) != 0 else -1)

