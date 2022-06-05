class TextEditor:

    def __init__(self):
        self.pos = -1
        self.n = 0
        self.s = ""

    def addText(self, text: str) -> None:   
        new_s = ""
        if self.pos >= 0:
            new_s = self.s[:self.pos + 1]
        new_s += text
        new_s += self.s[self.pos + 1:]
        self.s = new_s

        self.pos += len(text)
        self.n = len(self.s)
        # print(f"Adding: {self.s}, {self.pos}")

    def deleteText(self, k: int) -> int:
        new_pos = max(-1, self.pos - k)
        ret = self.pos - new_pos
        if new_pos >= 0:
            new_s = self.s[:new_pos + 1]
        else:
            new_s = ""
        new_s += self.s[max(0, self.pos + 1): ]
        self.s = new_s
        self.pos = new_pos
        self.n = len(self.s)
        # print(f"Deleting: {self.s}, {self.pos}")
        return ret

    def cursorLeft(self, k: int) -> str:
        self.pos = max(-1, self.pos - k)
        # print(f"Lefting: {self.pos}")
        return self.s[max(0, self.pos - min(10, self.pos + 1) + 1):self.pos + 1]
        

    def cursorRight(self, k: int) -> str:
        self.pos = min(self.n - 1, self.pos + k)
        # print(f"Righting: {self.pos}")
        return self.s[max(0, self.pos - min(10, self.pos + 1) + 1):self.pos + 1]


# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)