class Solution {
private:
    int palindrome_len(string& s, int l, int r) {
        
        while (l >= 0 && r < s.size() && s[l] == s[r])
            --l, ++r;
        
        return r - l - 1;
    }
public:
    string longestPalindrome(string s) {
        int start = 0, len = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            
            int l1 = 0, l2 = 0;
            l1 = palindrome_len(s, i, i);
            if (i + 1 != s.size())
                l2 = palindrome_len(s, i, i + 1);
            
            if (l1 > len || l2 > len)
                start = i, len = max(l1, l2);
        }
        
        return len%2? s.substr(start - len/2, len): s.substr(start - len/2 + 1, len);
    }
};