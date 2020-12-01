def solution(n):
    answer = 0
    temp = ""
    while(n>=3):
        n, m = divmod(n,3)
        temp += str(m)
    temp += str(n)
    
    for i in reversed(range(len(temp))):
        answer += int(temp[len(temp)-i-1]) * (3 ** i)

    return answer
    
if __name__ == "__main__":
    print(solution(45))
    print(solution(125))