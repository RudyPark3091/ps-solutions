n = input()
l = []

for letter in n:
    l.append(letter)

l.sort(reverse=True)
for item in l:
    print(item, end="")
print("")
