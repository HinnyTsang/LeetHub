class Solution {
private:
    int N;
    void backtracking(string& row, string& col, string& off, string& diag,
                      set<vector<string>>& result, vector<string>& temp,
                      int r) 
    {
        if (r == N) {
            result.insert(temp);
            return;
        }
        
        for (int c = 0; c < N; ++c) {
            if (col[c] == 'Q' || diag[N-1-r+c] == 'Q' || off[r+c] == 'Q') {
                continue;
            }
            col[c] = row[r] = diag[N-1-r+c] = off[r+c] = temp[r][c] = 'Q';
            backtracking(row, col, off, diag, result, temp, r + 1);
            col[c] = row[r] = diag[N-1-r+c] = off[r+c] = temp[r][c] = '.';
        }
        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        
        N = n;
        set<vector<string>> result;
        vector<string> temp(n, string(n, '.'));
        string diag(2*n - 1, '.'), off(2*n - 1, '.'), row(n, '.'), col(n, '.');
        
        backtracking(row, col, off, diag, result, temp, 0);

        return vector<vector<string>> (result.begin(), result.end());
    }
};