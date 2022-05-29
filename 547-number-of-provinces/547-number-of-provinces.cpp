class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, bool *seen, int i) {
        seen[i] = true;
        for (int j = 0; j < isConnected.size(); ++j) {
            if ( i != j && isConnected[i][j] == 1 && !seen[j]) {
                dfs(isConnected, seen, j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        bool *seen = new bool [n]();
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                dfs(isConnected, seen, i);
                ++count;
            }
        }
        return count;
    }
};