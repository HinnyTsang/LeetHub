class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> prev(1, nums[0]);
        
        for (auto& n: nums) {
            if (n > prev.back()) {
                prev.push_back(n);
            }
            else {
                auto it = lower_bound(prev.begin(), prev.end(), n);
                *(it) = n;
            }
            
        } 
        
        
        return prev.size();
    }
};