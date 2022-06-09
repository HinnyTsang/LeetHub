class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int r = s.size() - 1, l;
        
        for (; r >= 0 && s[r] == ' '; --r);
        
        l = r;
        for (; l >= 0 && isalpha(s[l]); --l);
        
        return r - l;
    }
};