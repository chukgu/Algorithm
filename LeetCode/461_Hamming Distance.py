class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x^y).count('1')

if __name__ == "__main__":
    s = Solution()
    print(s.hammingDistance(x = 1, y = 4))
    print(s.hammingDistance(x = 3, y = 1))