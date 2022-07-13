class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int dir [] = {0, 1, 0, -1, 0};
        int d = 0, i = 0, j = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> result(n*m, 0);
        
        for (int l = 0; l < n * m; ++l) {
            result[l] = matrix[i][j];
            matrix[i][j] = 101;
            
            
            int next_i = i + dir[d];
            int next_j = j + dir[d + 1];
            
            if (next_i  < 0 || next_i == n || next_j < 0 || next_j == m || matrix[next_i][next_j] == 101) {
                d = (d + 1) % 4;
                next_i = i + dir[d];
                next_j = j + dir[d + 1];
            }
            i = next_i, j = next_j;
        }
        
        return result;
    }
};