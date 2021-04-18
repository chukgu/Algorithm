class Solution:
    def climbStairs(self, n: int) -> int:
        stairs = [0,1,2]
        for i in range(3, n+1):
            stairs.append(stairs[i-2] + stairs[i-1])

        return stairs[n]

if __name__ == "__main__":
    s = Solution()
    print(s.climbStairs(n = 2))
    print(s.climbStairs(n = 3))