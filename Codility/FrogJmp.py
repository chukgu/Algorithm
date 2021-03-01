# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
import math

def solution(X, Y, D):
    res = math.ceil((Y-X) / D)
    return res

if __name__ == "__main__":
    print(solution(10, 85, 30))