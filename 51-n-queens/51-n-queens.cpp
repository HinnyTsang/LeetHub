class Solution {
private:
    int N;
    void backtracking(
        string& col, string& off, string& diag,
        vector<vector<string>>& result, vector<string>& temp,
        int r) 
    {
        if (r == N) {
            result.push_back(temp);
            return;
        }
        
        for (int c = 0; c < N; ++c) {
            if (col[c] == 'Q' || diag[N-1-r+c] == 'Q' || off[r+c] == 'Q') {
                continue;
            }
            col[c] = diag[N-1-r+c] = off[r+c] = temp[r][c] = 'Q';
            backtracking(col, off, diag, result, temp, r + 1);
            col[c] = diag[N-1-r+c] = off[r+c] = temp[r][c] = '.';
        }
        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        
        N = n;
        vector<vector<string>> result;
        vector<string> temp(n, string(n, '.'));
        string diag(2*n - 1, '.'), off(2*n - 1, '.'), col(n, '.');
        
        backtracking(col, off, diag, result, temp, 0);

        return result;
    }
};