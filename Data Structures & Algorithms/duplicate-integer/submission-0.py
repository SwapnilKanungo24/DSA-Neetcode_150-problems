class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        cnt = 1
        if len(nums) == 1: return False
        for i in range(1, len(nums)):
            if nums[i-1] == nums[i]:
                cnt += 1
        if cnt >= 2:
            return True
        else: return False