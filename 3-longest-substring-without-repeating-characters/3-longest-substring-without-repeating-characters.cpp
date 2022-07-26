class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> count;
        int len = 0;
        
        
        int l = 0;
        
        for (int r = 0; r < s.size(); ++r) {
            ++count[s[r]];
            while (count[s[r]] > 1) {
                --count[s[l++]];
            }
            len = max(len, r - l + 1);
        }
        
        return len;
    }
};