class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<pair<int, int>> bfs;
        int neib [5] = {1, 0, -1, 0, 1};
        int m = mat.size(), n = mat[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    bfs.emplace(i, j);
                }
                else {
                    mat[i][j] = -1;
                }
            }
        }
        
        while (!bfs.empty()) {
            int l = bfs.size();
            
            while (l-- > 0) {
                auto [i, j] = bfs.front(); bfs.pop();
        
                for (int k = 0; k < 4; ++k) {
                    int a = i + neib[k], b = j + neib[k + 1];
                    
                    if (a < 0 || b < 0 || a == m || b == n || mat[a][b] != -1)
                        continue;
                        
                    mat[a][b] = mat[i][j] + 1;
                    bfs.emplace(a, b);
                }
            }
        }
        
        return mat;
    }
};