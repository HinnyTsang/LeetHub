class Solution:
    def matchReplacement(self, s: str, t: str, mps: List[List[str]]) -> bool:
        
        n = len(s)
        m = len(t)
        
        possible_set = {mp[1]: set() for mp in mps}
        for mp in mps: 
            possible_set[mp[1]].add(mp[0])
        
        tset   = {_ for _ in t}
        
        i = 0
        while i <  n - m + 1:
            
            if s[i] not in possible_set.keys() and s[i] not in tset:
                i += 1
                print(i)
                continue
            
        
            ni = i
            for j in range(i, i + m):
                   
                if s[j] == t[j - i]:
                    continue

                elif s[j] not in tset and s[j] not in possible_set.keys():
                    ni = j + 1
                    print(j)
                    break
                
                elif s[j] in possible_set.keys() and t[j-i] in possible_set[s[j]]:
                    continue
                    
                else:
                    ni += 1
                    print(j)
                    break

                
                
            if ni == i:
                return True
            else:
                i = ni
        
        
        return False