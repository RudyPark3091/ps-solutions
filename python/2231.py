n = int(input())

for i in range(n):
    compose = i
    for letter in str(i):
        compose += int(letter)
    if compose == n:
        print(i)
        break
    if i == n-1:
        print(0)
