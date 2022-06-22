class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zeros = 0;
        int take_one = 0;
        int sum = 0, power = 1;
        for (int i = s.size() - 1; i >= 0 && sum  + power <= k; --i) {
            if (s[i] == '1') {
                sum += power;
                ++take_one;
            }
            power <<= 1;
        }
        return count(s.begin(), s.end(), '0') + take_one;
    }
};