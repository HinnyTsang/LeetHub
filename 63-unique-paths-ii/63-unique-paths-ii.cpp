class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        
        
        
        int n = g.size();
        int m = g[0].size();
        
        if (g[0][0] || g[n-1][m-1]) return 0;
        
        g[0][0] = 1;
        
        // fst col
        for (int i = 1; i < n; ++i) {
            if (g[i][0] == 1) {
                g[i][0] = 0;
            }
            else {
                g[i][0] = g[i-1][0];
            }
        }
        
        // fst row
        for (int i = 1; i < m; ++i) {
            if (g[0][i] == 1) {
                g[0][i] = 0;
            }
            else {
                g[0][i] = g[0][i-1];
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (g[i][j] == 1) {
                    g[i][j] = 0;
                }
                else {
                    g[i][j] = g[i-1][j] + g[i][j-1];
                }
            }
        }
        
        
        return g[n-1][m-1];
    }
};