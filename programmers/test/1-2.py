def solution(numbers):
    answer = []
    arr = []
    visited = [False for _ in range(len(numbers))]
    
    def foo(cnt):
        if cnt == 2:
            if sum(arr) in answer:
                pass
            else:
                answer.append(sum(arr))
            return
        
        for i in range(len(numbers)):
            if not visited[i]:
                arr.append(numbers[i])
                visited[i] = True
                foo(cnt + 1)
                visited[i] = False
    
    foo(0)
    answer.sort()
    
    return answer