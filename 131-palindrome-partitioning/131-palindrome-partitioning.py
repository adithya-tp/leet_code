class Solution:
    def __init__(self):
        self.ans = []
        self.curr_list = []
        self.s = None
        
    def _is_pal(self, s):
        return s == s[::-1]
    
    def _partition(self, idx, rem_string):
        if len(rem_string) == 1:
            self.curr_list.append(rem_string)
            self.ans.append(self.curr_list.copy()[1:-1])
            self.curr_list.pop()
            return
        
        s1 = rem_string[:idx + 1]
        s2 = rem_string[idx + 1: ]
        if not (self._is_pal(s1)):
            return
        
        self.curr_list.append(s1)
        for next_idx in range(len(s2)):
            self._partition(next_idx, s2)
        self.curr_list.pop()
        
    
    def partition(self, s: str) -> List[List[str]]:
        self.s = s + " "
        self._partition(-1, self.s)
        return self.ans