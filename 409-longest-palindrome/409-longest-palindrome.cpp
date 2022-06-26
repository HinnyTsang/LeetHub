class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> count;
        int result = 0, odd = 0;
        
        for (auto& c: s) {
            ++count[c];
        }
        
        for (auto& [c, cnt]: count) {
            result += cnt - (cnt%2);
            odd += cnt%2;
        }
        
        return result + (odd? 1: 0);
    }
};