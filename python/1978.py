n = int(input())
prime_list = []

for i in range(1, 1000):
    prime_list.append(i+1)

for i in range(1, 1001):
    for j in range(1, 1001):
        if i % j == 0 and j != 1:
            if i != j:
                try: prime_list.remove(i)
                except ValueError: pass

l = list(map(int, input().split()))
c = 0
for item in l:
    if item in prime_list:
        c += 1
    else:
        continue
print(c)
