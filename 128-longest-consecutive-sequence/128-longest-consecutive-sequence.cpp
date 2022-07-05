class Solution {

public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int max_len = 0;
        
        for (auto& num: nums) {
            if (!seen.count(num))
                continue;
            
            seen.erase(num);
            int len = 1, l = num-1, r = num+1;
        
            while (seen.count(l)) {
                seen.erase(l);
                --l, ++len;
            }
            while (seen.count(r)) {
                seen.erase(r);
                ++r, ++len;
            }
            max_len = max(max_len, len);
        }
        
        return max_len;
    }
};