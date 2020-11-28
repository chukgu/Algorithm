from itertools import combinations

def solution(numbers):
    comb = list(combinations(numbers, 2))
    answer = list(set([sum(i) for i in comb]))
    return answer

if __name__ == "__main__":
    print(solution([2,1,3,4,1]))
    print(solution([5,0,2,7]))