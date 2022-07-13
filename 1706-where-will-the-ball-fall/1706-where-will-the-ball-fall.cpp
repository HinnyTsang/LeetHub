class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int> result(m);
        
        iota(result.begin(), result.end(), 0);
        
        for (int row = 0; row < n; ++ row) {
            for (int col = 0; col < m; ++col) {
                int pos = result[col];
                
                if (pos != -1) {
                    if (grid[row][pos] == 1) {
                        if (pos == m-1 || grid[row][pos + 1] == -1) {
                            result[col] = -1;
                        }
                        else {
                            result[col] += 1;
                        }
                    }
                    else if (grid[row][pos] == -1) {
                        if (pos == 0 || grid[row][pos - 1] == 1) {
                            result[col] = -1;
                        }
                        else {
                            result[col] -= 1;
                        }
                    }
                }
            }
        } 
        
        return result;
    }
};