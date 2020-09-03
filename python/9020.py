def is_prime(num):
    if num == 1:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True


t = int(input())

for i in range(t):
    n = int(input())
    p1 = int(n // 2)
    p2 = int(n // 2)
    while not is_prime(p1) or not is_prime(p2):
        p1 -= 1
        p2 += 1
    print(p1, p2)
