class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> mat(n, vector<int>(m, 0));
        
        int max_len = 0;
        
        for (int r = 0; r < n; ++r) {
            mat[r][0] = matrix[r][0] == '1'? 1: 0;
            max_len = max(max_len, mat[r][0]);
        }
            
        for (int c = 0; c < m; ++c) {
            mat[0][c] = matrix[0][c] == '1'? 1: 0;
            max_len = max(max_len, mat[0][c]);
        }
        
        for (int r = 1; r < n; ++r) {
            for (int c = 1; c < m; ++c) {
                if (matrix[r][c] == '1') {
                    mat[r][c] += 1 + min({mat[r-1][c], mat[r][c-1], mat[r-1][c-1]});
                    max_len = max(max_len, mat[r][c]);
                }
            }
        }
        
        return max_len*max_len;
    }
};