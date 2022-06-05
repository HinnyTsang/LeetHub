class Solution {
private: 
    int N = 0;
    int nn;
    
    void bt(vector<vector<bool>>& temp, vector<bool>& dia, vector<bool>& off, vector<bool>& col, int r) {
        
        if (r == nn) {
            ++N;
            return;
        }
        
        for (int c = 0; c < nn; ++c) {
            if (!dia[nn-r-1+c] && !off[r+c] && !col[c]) {
                temp[r][c] = dia[nn-r-1+c] = off[r+c] = col[c] = true;
                bt(temp, dia, off, col, r+1);
                temp[r][c] = dia[nn-r-1+c] = off[r+c] = col[c] = false;
            }
        }
        
    }
    
public:
    int totalNQueens(int n) {
        
        nn = n;
        
        vector<bool> col(n, false), dia(2*n + 1, false), off(2*n+1, false);
        vector<vector<bool>> temp(n, vector<bool>(n, false));
        
        bt(temp, dia, off, col, 0);
        
        return N;
    }
};