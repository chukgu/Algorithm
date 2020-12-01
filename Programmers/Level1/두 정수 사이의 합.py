def solution(a, b):
    return sum(range(min(a,b),max(a,b)+1))

if __name__ == "__main__":
    print(solution(3,5))
    print(solution(3,3))
    print(solution(5,3))