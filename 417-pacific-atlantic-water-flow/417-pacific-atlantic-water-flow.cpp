class Solution {
private:
    int neib [5] = {-1, 0, 1, 0, -1};
    
    void dfs(vector<vector<bool>>& sea, vector<vector<int>>& h, int i, int j) {
        
        if (sea[i][j] == true) return;
        
        sea[i][j] = true;
        
        for (int k = 0; k < 4; ++k) {
        
            int a = i + neib[k];
            int b = j + neib[k + 1];
            
            if (a < 0 || b < 0 || a == h.size() || b == h[0].size())
                continue;
            
            else if (h[a][b] < h[i][j])
                continue;
            
            dfs(sea, h, a, b);
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<bool>> pac(m, vector<bool>(n)), atl(m, vector<bool>(n));
        
        vector<vector<int>> res;
        
        // first, last col
        for (int i = 0; i < m; ++i) {
            dfs(pac, heights, i, 0);
            dfs(atl, heights, i, n-1);
        }
        cout << "pass 1" << endl;
        // first, last row
        for (int j = 0; j < n; ++j) {
            dfs(pac, heights, 0, j);
            dfs(atl, heights, m-1, j);
        }
        cout << "pass 2" << endl;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
};