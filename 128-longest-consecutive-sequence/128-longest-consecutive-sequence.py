class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        
        nums_lookup = set(nums)
        max_len = 0
        for val in nums:
            # The val - 1 check is necessary because you don't need
            # to count starting from val in that case, because you've
            # already counted (or will count in the future) starting from val.
            # Very cool!
            if val - 1 not in nums_lookup:
                curr_num, curr_len = (val, 1)
                while curr_num + 1 in nums_lookup:
                    curr_num += 1
                    curr_len += 1
                max_len = max(max_len, curr_len)
        return max(max_len, curr_len)