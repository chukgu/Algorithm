class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        #print(f'{nums}: {target}')
        answer = {}
        for i, num in enumerate(nums):
            if target - num in answer:
                return [answer[target-num], i]
            answer[num] = i

if __name__ == "__main__":
    s = Solution()
    print(s.twoSum([2,7,11,15], 9))