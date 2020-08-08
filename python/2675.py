t = int(input())

for i in range(t):
    ip = input().split(" ")
    r = int(ip[0])
    s = list(ip[1])
    for item in s:
        print(item * r, end="")
    print("")
