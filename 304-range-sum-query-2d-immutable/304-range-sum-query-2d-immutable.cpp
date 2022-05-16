typedef vector<int> vi;
typedef vector<vi> vii;


class NumMatrix {
private:
    vii pfx;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        pfx = vii(n+1, vi(m+1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                pfx[i][j] += matrix[i-1][j-1] + pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pfx[row2+1][col2+1] + pfx[row1][col1] - pfx[row2+1][col1] - pfx[row1][col2+1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */