from collections import deque

def solution(s):
    return (''.join(sorted(deque(s), reverse=True)))#deque로 안 바꾸고 그냥 s로도 가능

if __name__ == "__main__":
    print(solution("Zbcdefg"))