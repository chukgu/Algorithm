class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        sub_max = [nums[0]]
        
        for i in range(1, len(nums)):
            sub_max.append(max(nums[i], nums[i]+sub_max[i-1]))
            # sub_max.append(nums[i] + (sub_max[i-1] if sub_max[i-1] > 0 else 0)) 이전꺼가 양수인 경우만 + 하는 방법

        return max(sub_max)

if __name__ == "__main__":
    s = Solution()
    print(s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
    print(s.maxSubArray([1]))
    print(s.maxSubArray([5,4,-1,7,8]))