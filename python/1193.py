import time

start_time = time.time()
#######################################################

x = int(input())
first, second = 0, 0

index = 0
while x - index > 0:
    x -= index
    index += 1

plus = index + 1
if index % 2 == 0:
    first = x
    second = plus - first
else:
    second = x
    first = plus - second
print(first, '/', second, sep='')

#######################################################
finish_time = time.time()

print("execution time:", finish_time - start_time)