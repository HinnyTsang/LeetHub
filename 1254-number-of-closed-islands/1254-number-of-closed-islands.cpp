class Solution {
private:
    bool remove_island(vector<vector<int>>& grid, int i, int j) {
        
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
            return false;
        else if (grid[i][j] == 1) 
            return true;
        
        grid[i][j] = 1;
        
        return 
            remove_island(grid, i+1, j) &
            remove_island(grid, i-1, j) &
            remove_island(grid, i, j+1) &
            remove_island(grid, i, j-1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int n_island = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    if (remove_island(grid, i, j))
                        ++n_island;
                }
            }
        }
        
        return n_island;
    }
};