class Solution:
    def rob(self, nums: list[int]) -> int:
        #공간 복잡도까지 고려한 것
        prev_max = 0
        curr_max = 0
        for num in nums:
            prev_max, curr_max = curr_max, max(prev_max + num, curr_max)
        return curr_max
        """ 더 정확한 점화식
        if not nums:
            return 0
        if len(nums) <= 2:
            return max(nums)
        
        dp = [nums[0], max(nums[0], nums[1])]
        for i in range(2, len(nums)):
            dp.append(max(dp[i-1], dp[i-2] + nums[i]))
        
        return dp[-1]
        """
        """
        size = len(nums)
        if not nums:
            return 0
        if size <= 2:
            return max(nums)
        if size == 3:
            return max(nums[0]+nums[2], nums[1])
        dp = [nums[0], nums[1], max(nums[0]+nums[2], nums[1])]
        for i in range(3, size):
            dp.append(nums[i] + max(dp[i-2], dp[i-3]))

        return max(dp)
        """

if __name__ == "__main__":
    s = Solution()
    print(s.rob(nums = [1,2,3,1]))
    print(s.rob(nums = [2,7,9,3,1]))
    print(s.rob(nums = [2,1,1,2]))
    print(s.rob(nums = [2,7,2,1,5,7,6,5,3,1,9,5]))
    print(s.rob(nums = [1]))
    print(s.rob(nums = [3]))
    print(s.rob(nums = [3,7]))
    print(s.rob(nums = [1,6,4]))
    print(s.rob(nums = [1,10,4,3]))