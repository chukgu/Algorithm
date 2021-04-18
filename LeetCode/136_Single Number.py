class Solution:
    #XOR 을 활용해서 풀이(XOR은 입력값이 서로 다르면 True, 서로 동일하면 False임 - Ex)0^0=0, 4^0=4, 4^4=0
    def singleNumber(self, nums: list[int]) -> int:
        result = 0
        for num in nums:
            result ^= num
        
        return result


if __name__ == "__main__":
    s = Solution()
    print(s.singleNumber(nums = [2,2,1]))
    print(s.singleNumber(nums = [4,1,2,1,2]))
    print(s.singleNumber(nums = [1]))