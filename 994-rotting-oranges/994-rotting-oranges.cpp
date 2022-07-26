class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int neig [] = {-1, 0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        int oranges = 0, rotten = 0, day = 0;
        queue<pair<int, int>> rot;
        
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    rot.emplace(i, j);
                }
                else if (grid[i][j] == 1) {
                    ++oranges;
                }
            }
        }
    
        while (oranges && rot.size()) {
            int c = rot.size();
            while (c--) {
                auto [i, j] = rot.front(); rot.pop();
                for (int k = 0; k < 4; ++k) {
                    int a = i + neig[k];
                    int b = j + neig[k + 1];
                    if (a < 0 || b < 0 || a == n || b == m || grid[a][b] != 1) 
                        continue;
                    grid[a][b] = 2;
                    --oranges;
                    rot.emplace(a, b);
                }
            }
            ++day;
        }
        
        return oranges == 0? day: -1;
    }
};