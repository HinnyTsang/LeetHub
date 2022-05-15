class Solution {
private:
    
    void bt(vector<vector<int>>& result, vector<int>& work, vector<int>& candidates, int& target, int i, int sum) {
        
        if (sum == target) {
            result.push_back(work);
            return;
        }
        
        if (sum > target || i == candidates.size()) {
            return;
        }
        
        for (int j=i; j < candidates.size();) {
            work.push_back(candidates[j]);
            sum += candidates[j];
            
            bt(result, work, candidates, target, j + 1, sum);
            
            work.pop_back();
            sum -= candidates[j];
            
            int curr = candidates[j];
            while (j < candidates.size() && candidates[j] == curr) ++j;
        }
        
        
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> result;
        vector<int> work;
        
        bt(result, work, candidates, target, 0, 0);
        
        return result;
        
    }
};