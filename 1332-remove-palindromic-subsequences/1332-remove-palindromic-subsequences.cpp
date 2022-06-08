class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.size() == 0) 
            return 0;
        int l = 0, r = s.size() - 1;
        while (r > l) {
            if (s[l] != s[r])
                return 2;
            ++l, --r;
        }
        return 1;
    }
};