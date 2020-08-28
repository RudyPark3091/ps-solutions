n = int(input())

counter = 0
i = 0
while True:
    if '666' in str(i):
        counter += 1

    if counter == n:
        print(i)
        break

    i += 1
