class Solution {
private:
    void remove_island(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        remove_island(grid, i+1, j);
        remove_island(grid, i-1, j);
        remove_island(grid, i, j+1);
        remove_island(grid, i, j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int n_island = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    ++n_island;
                    remove_island(grid, i, j);
                }
            }
        }
        
        return n_island;
    }
};