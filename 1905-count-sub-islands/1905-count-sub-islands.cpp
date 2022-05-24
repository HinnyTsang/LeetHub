class Solution {
private:
    
    bool is_sub_island(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if (i < 0 || j < 0 || i == grid1.size() || j == grid1[0].size())
            return true;
        
        if (grid2[i][j] == 0)
            return true;
        
        grid2[i][j] = 0;
        
        return is_sub_island(grid1, grid2, i+1, j) &
               is_sub_island(grid1, grid2, i-1, j) &
               is_sub_island(grid1, grid2, i, j+1) &
               is_sub_island(grid1, grid2, i, j-1) &
               grid1[i][j] == 1;
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m = grid1.size(), n = grid1[0].size();
        int n_sub_island = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1 && is_sub_island(grid1, grid2, i, j)) {
                    ++n_sub_island;
                }
            }
        }
        
        return n_sub_island;
    }
};