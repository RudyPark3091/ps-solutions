n = int(input())
s = input().split(' ')
ss = []
for item in s:
    ss.append(int(item))

maximum = max(ss)
minimum = min(ss)

print(minimum)
print(maximum)
