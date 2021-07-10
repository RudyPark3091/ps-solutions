w = input().lower()
r = 0

for letter in w:
    if letter == ' ':
        r += 2
    elif letter in ['a','b','c']:
        r += 3
    elif letter in ['d','e','f']:
        r += 4
    elif letter in ['g','h','i']:
        r += 5
    elif letter in ['j','k','l']:
        r += 6
    elif letter in ['m','n','o']:
        r += 7
    elif letter in ['p','q','r','s']:
        r += 8
    elif letter in ['t','u','v']:
        r += 9
    elif letter in ['w','x','y','z']:
        r += 10

print(r)
