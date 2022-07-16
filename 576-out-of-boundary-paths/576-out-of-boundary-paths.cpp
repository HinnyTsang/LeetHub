typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<vector<vector<int>>> viii;

class Solution {
private:
    const int MOD = 1e9+7;
    int m, n;
    int dfs(viii& dp, int i, int j, int move) {
        if (move < 0)
            return 0;
        
        if (i < 0 || j < 0 || i == m || j == n)
            return 1;
        
        if (dp[i][j][move] != -1) 
            return dp[i][j][move];
        
        dp[i][j][move] = 0;
        
        int top = dfs(dp, i-1, j, move - 1);
        int bot = dfs(dp, i+1, j, move - 1);
        int lef = dfs(dp, i, j-1, move - 1);
        int rig = dfs(dp, i, j+1, move - 1);
        
        dp[i][j][move] = ((((top % MOD + bot ) % MOD + lef ) % MOD + rig ) % MOD) % MOD;
        
        return dp[i][j][move];
    }
    
public:
    int findPaths(int _m, int _n, int maxMove, int startRow, int startColumn) {
        
        m = _m, n = _n;
        
        viii dp(m, vii(n, vi(maxMove + 1, -1)));
        
        return dfs(dp, startRow, startColumn, maxMove);                   
    }
};