typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int uniquePathsWithObstacles(vii& g) {
        
        int n = g.size(), m = g[0].size();
        
        if (g[0][0] == 1 || g.back().back() == 1) return 0;
        
        g[0][0] = 1;
        
        // first row
        for (int c = 1; c < m; ++c) {
            g[0][c] = g[0][c] == 1? 0: g[0][c-1];
        }
        // first col
        for (int r = 1; r < n; ++r) {
            g[r][0] = g[r][0] == 1? 0: g[r-1][0];
        }
        
        // others.
        for (int r = 1; r < n; ++r) {
            for (int c = 1; c < m; ++c) {
                g[r][c] = g[r][c] == 1? 0: g[r-1][c] + g[r][c-1];
            }
        }
        
        
        return g.back().back();
    }
};