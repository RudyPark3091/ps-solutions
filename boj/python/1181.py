n = int(input())
l = []

for i in range(n):
    l.append(input())

set_list = list(set(l))
sorted_list = sorted(set_list, key=lambda set_list: (len(set_list), set_list))
for item in sorted_list:
    print(item)
