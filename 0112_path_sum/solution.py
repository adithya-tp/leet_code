class Solution:
    def __init__(self):
        self.fs = 0
    def hasPathSum(self, r: TreeNode, s: int) -> bool:
        if r is None:
            return False
        if (r.left is not None):
            self.fs += r.val
            if(self.hasPathSum(r.left, s)):
                return True
            self.fs -= r.val
        if (r.right is not None):
            self.fs += r.val
            if(self.hasPathSum(r.right, s)):
                return True
            self.fs -= r.val
        if (r.left is None) and (r.right is None):
            self.fs += r.val
            if(self.fs == s):
                return True
            self.fs -= r.val          

