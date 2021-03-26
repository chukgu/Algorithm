class Solution:
    def reverseString(self, s: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        s.reverse()
        print(s)

if __name__ == "__main__":
    s = Solution()
    s.reverseString(["h","e","l","l","o"])
    s.reverseString(["H","a","n","n","a","h"])