# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def construct(self, nums: List[int], start: int, end: int) -> Optional[TreeNode]:
        if (start > end):
            return None
        if (start == end):
            return TreeNode(nums[start])
        mid = start + (end - start) // 2
        root = TreeNode(nums[mid])
        root.left = self.construct(nums, start, mid - 1)
        root.right = self.construct(nums, mid + 1, end)
        return root
    
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.construct(nums, 0, len(nums) - 1)