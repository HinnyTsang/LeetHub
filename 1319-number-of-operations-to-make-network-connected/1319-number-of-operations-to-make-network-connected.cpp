class Solution {
private:
    void dfs(vector<vector<int>>& g, bool *seen, int i) {
        seen[i] = true;
        for (auto& j: g[i]) {
            if (!seen[j])
                dfs(g, seen, j);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if (connections.size() < n - 1) return -1;
        
        vector<vector<int>> g(n);
        int n_groups = 0;
        bool *seen = new bool [n]();
        
        for (auto& edge: connections) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                dfs(g, seen, i);
                ++n_groups;
            }
        }
        
        return (n_groups - 1);
    }
};