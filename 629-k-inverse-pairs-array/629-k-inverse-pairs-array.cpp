class Solution {
public:
    int kInversePairs(int N, int K) {

        const int MOD = 1e9 + 7;
        int dp[1001][1001] = { 1 };
        
        /**
         *    0 1 2 3 4
         *  1 1 
         *  2 1 1
         *  3 1 2(2-1, 1-2) 0
         *  4 1 3 5 6
         */
        for (int n = 1; n <= N; ++n) {
            for (int k = 0; k <= K; ++k) {
                for (int i = 0; i <= min(k, n - 1); ++i) {
                    dp[n][k] = (dp[n][k] + dp[n-1][k-i]) % MOD;
                }
            }
        }        
        
        return dp[N][K];
    }
};