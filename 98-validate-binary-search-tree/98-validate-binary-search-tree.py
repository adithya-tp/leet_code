# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def helper(self, root: Optional[TreeNode], left_bound: Optional[int], right_bound: Optional[int]):
        if(root is None): return True
        is_within_bounds = True
        if(left_bound is None) and (right_bound is None):
            is_within_bounds = True
        else:
            if(not left_bound is None):
                is_within_bounds = root.val > left_bound
            if(not right_bound is None):
                is_within_bounds = (is_within_bounds) and (root.val < right_bound)

        if is_within_bounds:
            return self.helper(root.left, left_bound, root.val) and self.helper(root.right, root.val, right_bound)
        else:
            return False
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.helper(root, None, None)