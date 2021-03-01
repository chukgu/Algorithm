from collections import deque

def solution(progresses, speeds):
    answer = []
    x = int((99 - progresses[0]) / speeds[0]) + 1
    cnt = 1
    for i in range(1, len(progresses)):
        if(x < (int((99 - progresses[i]) / speeds[i]) + 1)):
            answer.append(cnt)
            cnt = 1
            x = (int((99 - progresses[i]) / speeds[i]) + 1)
        else:
            cnt += 1

    answer.append(cnt)

    return answer

if __name__ == "__main__":
    print(solution([93, 30, 55], [1, 30, 5]))
    print(solution([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1]))
    print(solution([10,20,25,40,60,90],[6,3,4,2,5,1]))