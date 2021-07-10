scores = []
result = 0

for i in range(5):
    scores.append(int(input()))

for score in scores:
    if score < 40:
        result += 40
    else:
        result += score

print(result / 5)
