class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res(n, vector<int>(n));
        
        int l = 0, a = 0, b = 0, m = n-1, N = n * n;
        
        --n; 
        while (l < N) {
            for (int i = b; i <= m; ++i) {
                res[a][i] = ++l;
            }
            ++a;
            for (int i = a; i <= n; ++i) {
                res[i][m] = ++l;
            }
            --m;
            for (int i = m; i >= b; --i) {
                res[n][i] = ++l;
            }
            --n;
            for (int i = n; i >= a; --i) {
                res[i][b] = ++l;
            }
            ++b;
        }
        
        return res;
    }
};