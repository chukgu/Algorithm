def solution(s):
    answer = ''
    cnt = 0
    for i in range(len(s)):
        if s[i].isspace():
            cnt = 0
            answer += " "
            continue
        if cnt % 2 == 0:
            answer += s[i].upper()
        else:
            answer += s[i].lower()
        cnt += 1
    return answer

if __name__ == "__main__":
    print(solution("try  hello world"))