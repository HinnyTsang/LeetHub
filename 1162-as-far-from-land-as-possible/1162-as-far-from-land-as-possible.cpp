class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int neib [5] = {-1, 0, 1, 0, -1};
        int n = grid.size(), max_dist = -1;
        queue<pair<int, int>> bfs;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    bfs.emplace(i, j);
                    grid[i][j] = 0;
                }
                else{
                    grid[i][j] = INT_MAX;
                }
            }
        }
        
        while (!bfs.empty()) {
            int m = bfs.size();
            
            while (m--) {
                auto [i, j] = bfs.front(); bfs.pop();
                int dist = grid[i][j];
                
                for (int k = 0; k < 4; ++k) {
                    int a = i + neib[k];
                    int b = j + neib[k + 1];
                    
                    if (a < 0 || b < 0 || a == n || b == n) 
                        continue;
                    
                    else if (grid[a][b] != INT_MAX)
                        continue;
                    
                    grid[a][b] = grid[i][j] + 1;
                    bfs.emplace(a, b);
                    max_dist = max(max_dist, grid[a][b]);
                }
            }
        }
        return max_dist;
    }
};