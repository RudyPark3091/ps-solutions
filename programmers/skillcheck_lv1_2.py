def solution(n):
    answer = ''

    string_list = ['수', '박']

    for i in range(n):
        answer += string_list[i % 2]

    return answer
