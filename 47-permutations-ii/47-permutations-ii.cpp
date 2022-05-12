class Solution {
private:
    
    void backtrack(set<vector<int>>& result, vector<int>& work, vector<int>& nums, set<int>& index) {
        
        // base case.
        if (work.size() == nums.size()) { 
            result.insert(work);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (index.count(i)) continue;
            
            work.push_back(nums[i]);
            index.insert(i);
            backtrack(result, work, nums, index);
            work.pop_back();
            index.erase(i);
        }
        
    }
    
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<int> index; 
        set<vector<int>> result;
        vector<int> work;
        
        backtrack(result, work, nums, index);
        
        return vector<vector<int>> (result.begin(), result.end());
        
    }
};