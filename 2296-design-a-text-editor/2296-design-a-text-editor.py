class TextEditor:

    def __init__(self):
        
        self.text = ''
        self.len = 0
        self.pos = 0

    def addText(self, text: str) -> None:
        
        if pos == 0:
            self.text = text + self.text
        elif pos == self.len:
            self.text = self.text + text
        else:
            self.text = self.text[:self.pos] + text + self.text[self.pos:]
        
        self.pos += len(text)
        self.len += len(text)

    def deleteText(self, k: int) -> int:
        
        
        if self.pos == self.len:
            self.text = self.text[:max(self.pos - k, 0)]
        else:
            self.text = self.text[:max(self.pos - k, 0)] + self.text[self.pos:]
        
        
        diff = self.len - len(self.text)
        self.pos -= diff
        self.len -= diff
        
        return diff
    

    def cursorLeft(self, k: int) -> str:
        
        self.pos = max(0, self.pos - k)
        
        if self.pos == 0:
            return ''
        
        else:
            return self.text[max(self.pos - 10, 0):self.pos]

        
    def cursorRight(self, k: int) -> str:
        
        self.pos = min(self.len, self.pos + k)
                
        if self.pos == 0:
            return ''
        
        else:
            return self.text[max(self.pos - 10, 0):self.pos]



# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)