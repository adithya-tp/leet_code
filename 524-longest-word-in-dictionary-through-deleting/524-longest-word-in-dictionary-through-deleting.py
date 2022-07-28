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
        max_len = 0
        max_len_word = ""
        dictionary.sort()
        for word in dictionary:
            if self.isTargetWordInSource(s, word):
                curr_word_len = len(word)
                if curr_word_len > max_len:
                    max_len = curr_word_len
                    max_len_word = word
        return max_len_word