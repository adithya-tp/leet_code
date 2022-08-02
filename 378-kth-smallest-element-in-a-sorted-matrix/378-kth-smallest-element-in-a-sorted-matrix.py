class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        a = []
        for row in matrix:
            for col in row:
                a.append(col)
        a.sort()
        
        return a[k - 1]