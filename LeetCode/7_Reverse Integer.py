class Solution:
    def reverse(self, x: int) -> int:
        x = str(x)
        x = int(x[::-1]) if int(x)>=0 else -int(x[len(x):0:-1])
        outside_x = 2**31
        if(-(outside_x) < x and x < (outside_x)-1):
            return x
        else:
            return 0

if __name__ == "__main__":
    s = Solution()
    print(s.reverse(123))
    print(s.reverse(-123))
    print(s.reverse(1534236469))