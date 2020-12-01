from math import gcd

def solution(n, m):
    answer = []
    answer.append(gcd(n,m))
    answer.append(n*m//gcd(n,m))
    return answer

if __name__ == "__main__":
    print(solution(3,12))
    print(solution(2,5))