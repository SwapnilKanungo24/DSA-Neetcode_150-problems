class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        map[nums[0]] = 0
        for i in range(1, len(nums)):
            diff = target - nums[i]
            if diff not in map:
                map[nums[i]] = i
            else:
                return list((map.get(diff), i))