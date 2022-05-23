class Solution {
private:
    int remove_island(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0)
            return 0;
        
        grid[i][j] = 0;
        
        return 1 + 
            remove_island(grid, i+1, j) + 
            remove_island(grid, i-1, j) + 
            remove_island(grid, i, j+1) + 
            remove_island(grid, i, j-1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int area = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    area = max(area, remove_island(grid, i, j));
                }
            }
        }
        
        return area;
    }
};

