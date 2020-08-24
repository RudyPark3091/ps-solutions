counterpart = {')': '(', ']': '['}

while True:
    stack = []
    sentence = input()
    if sentence == '.':
        break
    for letter in sentence:
        if letter in counterpart.values():
            stack.append(letter)
        elif letter in counterpart.keys() and len(stack) == 0:
            stack = [-1]
            break
        elif stack and letter in counterpart.keys():
            if stack[-1] == counterpart[letter]:
                stack.pop()
            elif stack[-1] != counterpart[letter]:
                stack = [-1]
                break

    if len(stack) != 0:
        print('no')
    else:
        print('yes')
