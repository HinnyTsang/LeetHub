class Solution {
private:
    void find_island(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>* bfs, int fill) {
        
        if (i < 0 || j < 0 || j == grid.size() || i == grid.size() || grid[i][j] < 0) 
            return;
        
        if (grid[i][j] == 0 ) {
            if (bfs) {
                bfs->emplace(i, j);
                grid[i][j] = -3;
            }
            return;
        }
        
        grid[i][j] = fill;
        find_island(grid, i+1, j, bfs, fill);    
        find_island(grid, i-1, j, bfs, fill);    
        find_island(grid, i, j+1, bfs, fill);    
        find_island(grid, i, j-1, bfs, fill);    
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        bool find_first = false;
        const int n = grid.size();
        queue<pair<int, int>> bfs;
        
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (find_first) {
                        find_island(grid, i, j, nullptr, -2);
                        i = j = n; // break two loop.
                    }
                    else {
                        find_island(grid, i, j, &bfs, -1);
                        find_first = true;
                    }
                }
            }
        }
        
        // for (auto r: grid) {
        //     for (auto c: r) {
        //         cout << c << " ";
        //     }
        //     cout << endl;
        // }
        
        int bridge_len = 1;
        int neib[5] = {-1, 0, 1, 0, -1};
        
        while (bfs.size() > 0) {
            
            int l = bfs.size();
            
            while (l--) {
                auto [i, j] = bfs.front(); bfs.pop();
                
                for (int k = 0; k < 4; ++k) {
                    int a = i + neib[k];
                    int b = j + neib[k+1];
                    
                    if (a < 0 || b < 0 || a == n || b == n)
                        continue;
                    
                    if (grid[a][b] == -1 || grid[a][b] == -3)
                        continue;
                    
                    if (grid[a][b] == -2)
                        return bridge_len;
                    
                    grid[a][b] = -3;
                    bfs.emplace(a, b);
                }
            }
            ++bridge_len;
        }
        
        return -1;
    }
};