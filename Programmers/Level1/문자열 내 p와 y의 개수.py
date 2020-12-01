def solution(s):
    s = s.lower()
    if s.count("p") == s.count("y"):
        return True
    else:
        return False

if __name__ == "__main__":
    print(solution("pPoooyY"))
    print(solution("Pyy"))