typedef vector<int> vi;
typedef vector<vi> vii;


class Solution {

    
public:
    vii matrixBlockSum(vii& mat, int k) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vii pfx(n+1, vi(m+1, 0));
        
        for (int r = 1; r <= n; ++r) {
            for (int c = 1; c <= m; ++c) {
                pfx[r][c] += mat[r-1][c-1] + pfx[r-1][c] + pfx[r][c-1] - pfx[r-1][c-1];
            }
        }
        
        for (auto& r: pfx) {
            for (auto& c: r) 
                cout << c << ", ";
            cout << endl;
        }
        
        for (int r = 1; r <= n; ++r) {
            for (int c = 1; c <= m; ++c) {
                int i = min(r+k, n);
                int j = min(c+k, m);
                int t = max(r-k-1, 0);
                int b = max(c-k-1, 0);
                
                mat[r-1][c-1] = pfx[i][j] + pfx[t][b] - pfx[i][b] - pfx[t][j]; 
            }
        }
        
        return mat;
    }
};