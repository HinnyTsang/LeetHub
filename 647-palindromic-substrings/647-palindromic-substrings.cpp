class Solution {
private:
    void find_palindrome(string& s, int l, int r, int& n) {
        while (l >= 0 && r < s.size() && s[l] == s[r])
            ++n, --l, ++r;
    }
public:
    int countSubstrings(string s) {
        
        int n = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            find_palindrome(s, i, i, n);
            find_palindrome(s, i, i+1, n);
        }
        
        return n;
    }
};