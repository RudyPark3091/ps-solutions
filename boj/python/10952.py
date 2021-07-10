while True:
    n = input()
    s = n.split(" ")
    if s[0] == "0" and s[1] == "0":
        break
    else:
        print(int(s[0]) + int(s[1]))