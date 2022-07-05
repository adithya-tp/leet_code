class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        c1 = max(cost1, cost2)
        c2 = min(cost1, cost2)
        ans = 0
        for n1 in range(1_000_010):
            if n1 * c1 > total:
                break
            n2 = (total - (n1 * c1)) // c2
            ans += n2 + 1
        
        return 1 if ans == 0 else ans