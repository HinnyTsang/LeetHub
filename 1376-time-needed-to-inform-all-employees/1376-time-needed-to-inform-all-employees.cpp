class Solution {

private:
    void dfs(vector<vector<int>>& tree, int i, vector<int>& informTime, int& time) {
        
        if (tree[i].size() == 0) {
            time = max(time, informTime[i]);
        }
        
        for (int& j: tree[i]) {
            informTime[j] += informTime[i];
            dfs(tree, j, informTime, time);
        }
    }
    
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> tree(n);
        
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                tree[manager[i]].push_back(i);
            }
        }
        
        int time = 0;
        
        dfs(tree, headID, informTime, time);
        
        return time;
    }
};