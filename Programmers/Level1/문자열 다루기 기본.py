def solution(s):
    if(len(s) == 4 or len(s) == 6):
        if(s.isdigit()):
            return True
    return False

if __name__ == "__main__":
    print(solution("a234"))
    print(solution("1234"))