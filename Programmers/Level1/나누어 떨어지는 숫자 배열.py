def solution(arr, divisor):
    answer = []
    for i in arr:
        if(i % divisor == 0):
            answer.append(i)
    if(len(answer) == 0):
        answer.append(-1)
    else:
        answer.sort()
    return answer

    #다른 사람의 풀이
    #return sorted([item for item in arr if item % divisor == 0]) or [-1]
    #- 만약 sorted된 리스트가 빈 리스트라면(거짓) or에 의해서 참인 값 [-1]을 return 한다
    #- 파이썬에서 0, [], " ", False 등등은 거짓 그 외에 나머지 값은 참

if __name__ == "__main__":
    print(solution([5, 9, 7, 10], 5))
    print(solution([2, 36, 1, 3], 1))
    print(solution([3,2,6], 10))