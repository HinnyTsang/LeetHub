class Solution {
private:
    int *neig;
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int i, int j) {

        ocean[i][j] = 2;
        
        for (int k = 0; k < 4; ++k) {
            int a = i + neig[k];
            int b = j + neig[k + 1];
        
            if (a < 0 || b < 0 || a >= heights.size() || b >= heights[0].size() || ocean[a][b] == 2)
                continue;
            
            if (heights[a][b] < heights[i][j])
                continue;
            
            dfs(heights, ocean, a, b);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        neig = new int []{-1, 0, 1, 0, -1};
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> pac(n, vector<int>(m, 0)), atl(n, vector<int>(m, 0));
        vector<vector<int>> result;
        
        for (int i = 0; i < n; ++i) {
            dfs(heights, pac, i, 0);
            dfs(heights, atl, i, m-1);
        }
        for (int j = 0; j < m; ++j) {
            dfs(heights, pac, 0, j);
            dfs(heights, atl, n-1, j);
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pac[i][j] == 2 && atl[i][j] == 2)
                    result.push_back({i, j});
            }
        }
        
        return result;
    }
};