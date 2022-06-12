class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int max_score = 0;
        int l = 0, r = 0, n = nums.size(), score = 0;
        unordered_map<int, int> n_cnt;
        
        
        for (; r < n; ++r) {
            ++n_cnt[nums[r]];
            score += nums[r];
            while (n_cnt[nums[r]] > 1) {
                score -= nums[l];
                --n_cnt[nums[l++]];
            }
            max_score = max(max_score, score);
        }
        return max_score;
    }
};