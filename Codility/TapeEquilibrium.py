def solution(A):
    ''' # Time Out Error
    min_num = abs(sum(A[:1]) - sum(A[1:]))
    for i in range(2,len(A)):
        if(min_num > abs(sum(A[:i]) - sum(A[i:]))):
            min_num = abs(sum(A[:i]) - sum(A[i:]))
    return min_num
    '''
    part_a = A[0]
    part_b = sum(A) - A[0]
    min_num = abs(part_a - part_b)
    for i in range(2,len(A)):
        part_a += A[i-1]
        part_b -= A[i-1]
        diff = abs(part_a - part_b)
        if(min_num > diff):
            min_num = diff
    return min_num

if __name__ == "__main__":
    print(solution([3,1,2,4,3]))
    print(solution([5,2]))
    print(solution([5,4,3,2,1]))
    