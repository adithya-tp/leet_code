class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        din = [0 for _ in range(n)]
        dout = [0 for _ in range(n)]
        
        for pair in trust:
            dout[pair[0] - 1] += 1
            din[pair[1] - 1] += 1
        
        for idx in range(n):
            if (dout[idx] == 0) and (din[idx] == n - 1):
                return idx + 1
        return -1