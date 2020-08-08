n = input()

try:
    pro = int(n)
    print(pro+48)
except(ValueError):
    print(ord(n))

