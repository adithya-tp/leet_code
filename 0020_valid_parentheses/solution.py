from collections import deque
class Solution:
    def isValid(self, s: str) -> bool:
        opening = "{[("
        open_close = {"{":"}", "(":")", "[":"]"}
        stack = deque()
        count = 0
        for bracket in s:
            if bracket in opening:
                count += 1
                stack.append(bracket)
            else:
                try:
                    popped = stack.pop()
                    count -=1
                except:
                    return False
                if bracket != open_close[popped]:
                    return False
        if count == 0:
            return True
        return False
