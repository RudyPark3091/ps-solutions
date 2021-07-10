import sys

while True:
    t = sys.stdin.readline()
    if t == "":
        break
    else:
        s = t.split()
        print(int(s[0]) + int(s[1]))
