def solution(numbers, hand):
    answer = ""
    matrix = [[row,col] for col in range(4) for row in range(3)]
    matrix.insert(0,[0,0])#숫자 키패드와 맞추기 위해 dummy list 추가
    left = [1,4,7]
    right = [3,6,9]
    now_L = 10
    now_R = 12

    for num in numbers:
        if num in left:
            now_L = num
            answer += "L"
        elif num in right:
            now_R = num
            answer += "R"
        else:
            if num == 0:
                num = 11
            L_distance = abs(matrix[num][0] - matrix[now_L][0]) + abs(matrix[num][1] - matrix[now_L][1])
            R_distance = abs(matrix[num][0] - matrix[now_R][0]) + abs(matrix[num][1] - matrix[now_R][1])
            if L_distance < R_distance:
                now_L = num
                answer += "L"
            elif R_distance < L_distance:
                now_R = num
                answer += "R"
            else:
                if hand == "right":
                    now_R = num
                    answer += "R"
                else:
                    now_L = num
                    answer += "L"

    return answer

if __name__ == "__main__":
    print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"))
    print(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], "left"))
    print(solution([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], "right"))