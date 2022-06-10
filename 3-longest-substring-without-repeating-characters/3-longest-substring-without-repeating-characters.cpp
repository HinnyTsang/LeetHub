class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> number_of_char(255, 0);
        int l = 0, r = 0;
        int max_length = 0;
        for (; r < s.size(); ++r) {
            ++number_of_char[s[r]];
            while (number_of_char[s[r]] > 1) {
                --number_of_char[s[l++]];
            }
            max_length = max(max_length, r - l + 1);
        }
        return max_length;
    }
};