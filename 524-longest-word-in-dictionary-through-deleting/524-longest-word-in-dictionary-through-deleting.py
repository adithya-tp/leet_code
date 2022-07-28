class Solution:
    def isTargetWordInSource(self, src, trg):
        trg_ptr = 0
        trg_len = len(trg)
        for char in src:
            if char == trg[trg_ptr]:
                trg_ptr += 1
                if trg_ptr == trg_len:
                    return True
        return False
            
    
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        # Sort lengthwise descending, and lexicographically ascending
        dictionary.sort(key=lambda x: (-len(x), x))
        for word in dictionary:
            if self.isTargetWordInSource(s, word):
                return word
        return ""
