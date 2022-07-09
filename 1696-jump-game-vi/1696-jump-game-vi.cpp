class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        deque<int> prev;
        int n = nums.size();
        prev.push_back(0);
        
        
        for (int i = 1; i < n; ++i) {
            while(!prev.empty() && prev.front() < i - k) {
                prev.pop_front();
            }    
            nums[i] += nums[prev.front()];
            while(!prev.empty() && nums[prev.back()] < nums[i]) {
                prev.pop_back();
            }
            prev.push_back(i);
        }
        
        return nums.back();
    }
};