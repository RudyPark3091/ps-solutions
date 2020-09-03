def is_prime(num):
    if num == 1:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True


while True:
    counter = 0
    n = int(input())
    if n == 0:
        break

    for i in range(n+1, 2 * n + 1):
        if is_prime(i):
            counter += 1
    print(counter)
