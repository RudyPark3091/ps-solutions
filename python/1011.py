t = int(input())

for test_case in range(t):
    x, y = map(int, input().split())
    distance = y - x
    trial = 0

    index = 1
    while distance > 0:
        distance -= index
        trial += 1
        if distance <= 0:
            break
        distance -= index
        trial += 1
        index += 1

    print(trial)
