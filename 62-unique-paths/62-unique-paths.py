class Solution:
    def fact(self, n):
        if n < 1:
            return 1
        return n * self.fact(n - 1)
    
    def uniquePaths(self, m: int, n: int) -> int:
        num = self.fact(m + n - 2)
        denom = self.fact(m - 1) * self.fact(n - 1)
        return num // denom