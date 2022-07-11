class Solution:
    def solve(self, nums, l, r):
        arr = nums[l:r+1]
        arr.sort()
        d = arr[1] - arr[0]
        for i in range(2, len(arr)):
            if arr[i] - arr[i - 1] != d:
                return False
        return True
    
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        n = len(nums)
        q = len(l)
        ans = []
        for (li, ri) in zip(l, r):
            ans.append(self.solve(nums, li, ri))
        return ans
        