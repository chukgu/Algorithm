def solution(phone_number):
    answer = ""
    for i in range(len(phone_number)-4):
        answer += "*"
    answer += phone_number[-4:]
    return answer

    #다른 사람의 풀이
    #return "*"*(len(phone_number)-4) + phone_number[-4:]

if __name__ == "__main__":
    print(solution("01033334444"))
    print(solution("027778888"))