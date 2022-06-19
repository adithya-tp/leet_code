class Solution:
    def greatestLetter(self, s: str) -> str:
        n = len(s)
        low = [False for _ in range(26)]
        upp = [False for _ in range(26)]
        for ch in s:
            if ch.isupper():
                upp[ord(ch) - ord('A')] = True
            else:
                low[ord(ch) - ord('a')] = True
        
        ans = ""
        for idx in range(26):
            if low[idx] and upp[idx]:
                ans = chr(idx + ord('A'))
        return ans