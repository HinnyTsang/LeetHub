class Solution {
private:
    
    void backtrack(vector<vector<int>>& result, vector<int>& work, int k, int n, int sum) {
        
        // impossible to construct a solution.
        if (sum + k > n) return;
        
        if (k == 0 && sum == n) {
            result.push_back(work);
            return;
        }        
        
        for (int i = work.size()? work.back() + 1: 1; i < 10 && i + sum <= n; ++i) {
            
            work.push_back(i);
            backtrack(result, work, k - 1, n, sum + i);
            work.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> result;
        vector<int> work;
        backtrack(result, work, k, n, 0);
        return result;
    }
};