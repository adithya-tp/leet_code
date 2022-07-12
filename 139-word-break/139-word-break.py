class Solution:
    def __init__(self):
        self.dict = None
        # self.curr_list = []
        
    def _is_word(self, word):
        return len(word) == 0 or word in self.dict
    
    @lru_cache(None)
    def _partition(self, idx, rem_string):
        if len(rem_string) == 1:
            # print("Found partition: ", self.curr_list)
            return True
        
        s1 = rem_string[:idx + 1]
        s2 = rem_string[idx + 1: ]
        if not (self._is_word(s1)):
            return False
        
        # self.curr_list.append(s1)
        for next_idx in range(len(s2)):
            possible = True and self._partition(next_idx, s2)
            if possible:
                return True
        # self.curr_list.pop()
        return False
    
    
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        self.dict = set(wordDict)
        s = s + " "
        return self._partition(-1, s)