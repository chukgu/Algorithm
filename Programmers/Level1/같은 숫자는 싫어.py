def solution(arr):
    answer = []
    answer.append(arr[0])
    for i in range(1, len(arr)):
        if answer[-1] != arr[i]:
            answer.append(arr[i])
            
    return answer

if __name__ == "__main__":
    print(solution([1,1,3,3,0,1,1]))
    print(solution([4,4,4,3,3]))