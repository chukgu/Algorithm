def solution(a, b):
    answer = ["FRI","SAT","SUN","MON","TUE","WED","THU"]
    dic={1:31, 2:29, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
    cnt = 0
    for i in range(1, a):
        cnt += dic.get(i)
    cnt += b

    return answer[(cnt % 7)-1]

if __name__ == "__main__":
    print(solution(5,24))