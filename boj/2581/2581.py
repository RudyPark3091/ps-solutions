m = int(input())
n = int(input())
prime_list = []

for i in range(m, n+1):
    prime_list.append(i)
if 1 in prime_list:
    prime_list.remove(1)

for i in range(2, n):
    j = 2
    while i * j <= n:
        try:
            prime_list.remove(i * j)
        except ValueError: pass
        j += 1
if len(prime_list) == 0:
    print(-1)
    exit(0)
print(sum(prime_list))
print(prime_list[0])
