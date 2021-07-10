n = int(input())

def hanoi(n, dep, des, aux):
    if n == 1:
        print(str(dep) + " " + str(des))
        return
    hanoi(n-1, dep, aux, des)
    print(str(dep) + " " + str(des))
    hanoi(n-1, aux, des, dep)

print(2 ** n - 1)
hanoi(n, 1, 3, 2)