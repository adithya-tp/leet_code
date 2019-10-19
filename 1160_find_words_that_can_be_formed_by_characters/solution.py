class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        total = 0
        flag = 0
        chars_copy = chars
        for word in words:
            for w in word:
                if w not in chars_copy:
                    flag = 1
                    break
                else:
                    chars_copy = chars_copy.replace(w, '', 1)
            if(flag == 0):
                total += len(word)
            flag = 0
            chars_copy = chars
            
        return total
