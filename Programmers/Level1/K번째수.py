def solution(array, commands):
    answer = []
    for c in commands:
        answer.append(sorted(array[c[0]-1:c[1]])[c[2]-1])
    return answer

    #다른 사람의 풀이
    #return list(map(lambda x:sorted(array[x[0]-1:x[1]])[x[2]-1], commands))

if __name__ == "__main__":
    print(solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]]))