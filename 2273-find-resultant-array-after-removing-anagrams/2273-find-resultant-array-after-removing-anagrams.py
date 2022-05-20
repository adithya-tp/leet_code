class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        save_words = words.copy()
        for idx, val in enumerate(words):
            words[idx] = "".join(sorted(words[idx].lower()))
        
        indexExists = True
        while indexExists:
            indexExists = False
            n = len(words)
            for idx in range(1, n):
                if words[idx] == words[idx - 1]:
                    save_words.pop(idx)
                    words.pop(idx)
                    indexExists = True
                    break
        return save_words
                    
                