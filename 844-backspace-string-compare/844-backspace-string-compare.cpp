class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
    
        for (;i >= 0 || j >= 0; --i, --j) {
            
            int hash_s = 0;
            int hash_t = 0;
            
            while (i >= 0 && (hash_s > 0 || s[i] == '#')) {
                hash_s += s[i] == '#'? 1: -1;
                --i;
            }
            
            while (j >= 0 && (hash_t > 0 || t[j] == '#')) {
                hash_t += t[j] == '#'? 1: -1;
                --j;
            }
            
            if (i < 0 && j < 0) {
                return true;
            }
            else if ( i < 0 || j < 0) {
                return false;
            }
            else if (s[i] != t[j]) {
                return false;
            }
        }
        
        return i == j; 
    }
};