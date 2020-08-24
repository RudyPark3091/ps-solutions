n = int(input())

series = []
stack = []
result = []
flag = True

for i in range(n):
    series.append(int(input()))

push_num = 1
for number in series:
    if len(stack) == 0:
        stack.append(push_num)
        push_num += 1
        result.append('+')

    if stack and number == stack[-1]:
        stack.pop()
        result.append('-')

    elif stack and number > stack[-1]:
        while push_num <= number:
            stack.append(push_num)
            push_num += 1
            result.append('+')
        stack.pop()
        result.append('-')

    elif stack and number != stack[-1]:
        print('NO')
        flag = False
        break

if flag:
    for pm in result:
        print(pm)
