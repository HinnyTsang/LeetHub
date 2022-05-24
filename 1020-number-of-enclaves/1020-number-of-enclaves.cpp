class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int& mode) {
        /**
         * mode 1 -> 1 -> 2
         * mode 0 -> 2, 1 -> 0
         */
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size()) {
            mode = 0;
            return 0;
        }
        
        if (mode == 1 && (grid[i][j] == 0 || grid[i][j] == 2))
            return 0;
        
        if (mode == 0 && (grid[i][j] == 0))
            return 0;
        
        grid[i][j] = mode == 1? 2: 0;
        
        return dfs(grid, i-1, j, mode) +
               dfs(grid, i+1, j, mode) +
               dfs(grid, i, j+1, mode) +
               dfs(grid, i, j-1, mode) + 1;   
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0, mode = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    mode = 1;
                    int area = dfs(grid, i, j, mode);
                    count += mode? area: 0;
                }
            }
        }
        
        return count;
    }
};