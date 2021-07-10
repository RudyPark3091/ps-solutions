s = input()
result = 0

c = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]

for item in c:
    ss = s.split(item)
    s = "/".join(ss)

print(len(s))
