class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int result = 0;
        vector<vector<int>> prefix_sum(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                prefix_sum[i][j] = matrix[i-1][j-1] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int a = 0; a < i; ++a) {
                    for (int b = 0; b < j; ++b) {
                        int curr = prefix_sum[i][j] - prefix_sum[a][j] - prefix_sum[i][b] + prefix_sum[a][b];
                        if (curr == target)
                            ++result;
                    }
                }
            }
        }
        return result;
    } 
};