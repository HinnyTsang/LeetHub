class Solution {
private:
    
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& bt, int i) {
        
        if (i == nums.size()) return;
        
        bt.push_back(nums[i]);
        result.push_back(bt);
        for (int j = i + 1; j < nums.size();) {
            backtrack(nums, result, bt, j);
            int curr = nums[j];
            while(j < nums.size() && nums[j] == curr) ++j;
        }
        bt.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        vector<int> bt;
        
        result.push_back(bt);
        
        for (int i = 0; i < nums.size();) {
            backtrack(nums, result, bt, i);
            int curr = nums[i];
            while(i < nums.size() && nums[i] == curr) ++i;
        }
        
        return result;
    }
};