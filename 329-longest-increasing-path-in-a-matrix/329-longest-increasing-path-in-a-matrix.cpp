class Solution {
private:
    int n, m;
    int neib [5] = {1, 0, -1, 0, 1};
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        
        // boundary checking
        if (i < 0 || j < 0 || i == n || j == m)
            return 0;
        
        // if already calculated
        if (dp[i][j] > 0)
            return dp[i][j];
        
        // local minimum
        if (matrix[max(i-1, 0)][j] >= matrix[i][j] && 
            matrix[min(i+1, n-1)][j] >= matrix[i][j] &&
            matrix[i][max(j-1,0)] >= matrix[i][j] &&
            matrix[i][min(j+1,m-1)] >= matrix[i][j] ) {
            dp[i][j] = 1;
            return dp[i][j];
        }
            
        // go for the next.
        for (int k = 0; k < 4; ++k) {
            int a = i + neib[k];
            int b = j + neib[k+1];
            if (a < 0 || b < 0 || a == n || b == m)
                continue;
            if (matrix[a][b] < matrix[i][j]) {
                if (dp[a][b] == -1) {
                    dp[a][b] = dfs(matrix, dp, a, b);    
                }
                dp[i][j] = max(dp[i][j], dp[a][b]+1);
            }
        }
        
        return dp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        
        int max_path = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(matrix, dp, i, j);
                max_path = max(max_path, dp[i][j]);
            }
        }
        
        return max_path;
    }
};