class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] += min({matrix[i-1][j], matrix[i-1][max(j-1, 0)], matrix[i-1][min(j+1, m-1)]});
            }    
        }
        
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};