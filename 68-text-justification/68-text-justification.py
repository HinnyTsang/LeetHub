class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        
        result = []
        n = len(words)
        
        i = 0
        
        while i < n:
            
            word = [words[i]]
            curr = ''
            line_len = len(word[0])
            zero_len = 0
            
            i += 1
            
            while i < n and line_len + len(words[i]) + zero_len + 1 <= maxWidth:
                word.append(words[i])
                line_len += len(words[i])
                zero_len += 1
                i += 1
            
            zero_len = maxWidth - line_len
            avg_zero = zero_len // max(len(word) - 1, 1)
            
            
            if i == n:
                for wd in word:
                    curr += wd
                    if len(curr) < maxWidth:
                        curr += ' '
                
                while len(curr) < maxWidth:
                    curr += ' '
                
                result.append(curr)
            else:
                
                spaces = [' '*avg_zero for _ in range(len(word) - 1)]
                
                space_now = avg_zero * (len(word) - 1)
                
                l = 0
                
                while l < len(spaces) and zero_len - space_now > 0:
                    spaces[l] += ' '
                    l += 1
                    space_now += 1
                
                
                for wd, sp in zip(word, spaces):
                    curr += wd + sp
                
                curr += word[-1]
                
                curr += (maxWidth - len(curr))*' '
                
                result.append(curr)
            
        return result
        