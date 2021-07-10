n = int(input())

ages = []
names = []

for i in range(n):
    ip = input().split()
    ages.append(int(ip[0]))
    names.append(ip[1])

member_info = list(zip(ages, names))
sorted_list = sorted(member_info, key=lambda member_info: member_info[0])

for item in sorted_list:
    print(item[0], item[1])
