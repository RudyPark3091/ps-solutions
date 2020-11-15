def solution(participant, completion):
    participant.sort()
    completion.sort()

    answer = ''
    for index in range(len(completion)):
        if participant[index] != completion[index]:
            answer = participant[index]
            break

    if participant[-1] != completion[-1]:
        answer = participant[-1]

    return answer
