# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    return sum(range(1, len(A)+2)) - sum(A)
    

if __name__ == "__main__":
    print(solution([2,3,1,5]))
    print(solution([1]))