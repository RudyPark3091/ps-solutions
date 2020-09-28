def solution(numbers):
    answer = []
    
    for i in range(len(numbers)):
        for j in range(len(numbers)):
            if i != j:
                num = numbers[i] + numbers[j]
                if num in answer:
                    pass
                else:
                    answer.append(num)
    answer.sort()
    return answer