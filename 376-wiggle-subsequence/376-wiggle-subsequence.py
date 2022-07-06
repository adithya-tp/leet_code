class Solution:
    def __init__(self):
        self.max_len = 1
        self.curr_len = 1
        self.arr = None
    
    def wiggleMaxLength(self, nums: List[int]) -> int:
        l = []
        n = len(nums)
        first = True
        for i in range(1, n):
            diff = nums[i] - nums[i - 1]
            if diff == 0:
                continue
            
            if first:
                first = False
                curr = 'U' if diff > 0 else 'D'
                l.append(curr)
            elif (diff > 0) and curr == 'D':
                l.append('U')
                curr = 'U'
            elif (diff < 0) and curr == 'U':
                l.append('D')
                curr = 'D'
        return len(l) + 1