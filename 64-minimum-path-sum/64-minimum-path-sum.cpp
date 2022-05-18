class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        // first row.
        for (int c=1; c<m; ++c)
            grid[0][c] += grid[0][c-1];
        
        // first column.
        for (int r=1; r<n; ++r)
            grid[r][0] += grid[r-1][0];
        
        // dp
        for (int r = 1; r < n; ++r)
            for (int c = 1; c < m; ++c)
                grid[r][c] += min(grid[r-1][c], grid[r][c-1]);
        
        return grid[n-1][m-1];
    }
};