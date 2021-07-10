t = int(input())

for i in range(t):
    stack = []
    ip = input()

    for letter in ip:
        if letter == '(':
            stack.append(1)
        elif stack and letter == ')':
            stack.pop()
        else:
            stack = [-1]
            break

    if len(stack) != 0:
        print('NO')
    else:
        print('YES')
