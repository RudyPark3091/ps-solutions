def solution(arr, divisor):
    answer = []

    arr.sort()
    for item in arr:
        if item % divisor == 0:
            answer.append(item)

    if len(answer) == 0:
        answer = [-1]

    return answer
