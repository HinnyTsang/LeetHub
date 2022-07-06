class Solution {
private:
    void backtracking (vector<int>& candidates, vector<vector<int>>& result, vector<int>& bt, int i, int& target, int &sum) {
        
        bt.push_back(candidates[i]);
        sum += candidates[i];
        
        if (sum == target) 
            result.push_back(bt);
        
        if (sum < target) {
            for (int j = i; j < candidates.size(); ) {
                backtracking(candidates, result, bt, j, target, sum);
                int curr = candidates[j];
                while (j < candidates.size() && candidates[j] == curr) ++j;
            }
        }
        sum -= candidates[i];
        bt.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> bt;
        int n = candidates.size(), sum = 0;
        
        sort(candidates.begin(), candidates.end());
        if (candidates[0] > target) return result;
        
        for (int i = 0; i < n && candidates[i] <= target;) {
            backtracking(candidates, result, bt, i, target, sum);
            int curr = candidates[i];
            while (i < n && candidates[i] == curr) ++i;
        }
        
        return result;
    }
};