class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        ans_list = [1 for _ in range(n)]
        for idx in range(0, n - 1):
            if (ratings[idx + 1] > ratings[idx]):
                ans_list[idx + 1] = ans_list[idx] + 1
        
        for idx in range(n - 1, 0, -1):
            if (ratings[idx - 1] > ratings[idx]) and (ans_list[idx - 1] <= ans_list[idx]):
                ans_list[idx - 1] = ans_list[idx] + 1
        
        return sum(ans_list)