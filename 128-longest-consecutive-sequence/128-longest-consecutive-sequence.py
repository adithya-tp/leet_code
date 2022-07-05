class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        
        nums.sort()
        curr_val, curr_len = (nums[0], 1)
        max_len = 1
        for idx in range(1, n):
            if nums[idx] == nums[idx - 1] + 1:
                curr_len += 1
            elif nums[idx] == nums[idx - 1]:
                continue
            else:
                max_len = max(max_len, curr_len)
                curr_val, curr_len = (nums[idx], 1)
        
        return max(max_len, curr_len)