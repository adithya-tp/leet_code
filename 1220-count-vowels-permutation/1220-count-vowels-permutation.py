class Solution:
    def __init__(self):
        self.n = None
        self.ans = 0
        self.mod = int(1e9 + 7)
        self.map = {
            ' ': ['a','e','i','o','u'],
            'a': ['e'],
            'e': ['a', 'i'],
            'i': ['a', 'e', 'o', 'u'],
            'o': ['i', 'u'],
            'u': ['a']
        }
        self.dp = None

    def brute_force(self, idx, last_char): #, curr_perm_size):
        if idx == self.n:
            return 1
            
        if self.dp[last_char][idx] != -1:
            return self.dp[last_char][idx]
        
        ans = 0
        next_list = self.map[last_char]
        for next_char in next_list:
            ans += self.brute_force(idx + 1, next_char)
        self.dp[last_char][idx] = ans
        return ans
    
    def countVowelPermutation(self, n: int) -> int:        
        self.n = n
        self.dp = {k: [-1 for _ in range(n)] for k in ' aeiou'}
        self.brute_force(0, ' ')
        return self.dp[' '][0] % self.mod