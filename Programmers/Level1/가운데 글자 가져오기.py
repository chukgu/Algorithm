def solution(s):
    answer = ''
    size = len(s)
    if(size % 2 == 0):
        answer = s[int(size/2-1) : int(size/2 +1)]
    else:
        answer = s[int(size/2) : int(size/2 +1)]
    return answer

    #다른 사람의 풀이
    #return str[(len(str)-1)//2:len(str)//2+1]

if __name__ == "__main__":
    print(solution("abcde"))
    print(solution("qwer"))