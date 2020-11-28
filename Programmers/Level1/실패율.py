def solution(N, stages):
    a = {}
    size = len(stages)
    for i in range(N):
        cnt = stages.count(i+1)
        if size == 0:
            a[i+1] = 0
        else:
            a[i+1] = cnt/size
            size = size - cnt
    answer = sorted(a, key=lambda x: a[x], reverse=True)
    return answer

if __name__ == "__main__":
    print(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]))
    print(solution(4, [4,4,4,4,4]))
    print(solution(4, [1,1,1,1]))