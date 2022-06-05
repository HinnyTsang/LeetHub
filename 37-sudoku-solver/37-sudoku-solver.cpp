class Solution {
    
private:
    vector<int> rows, cols, boxs;
    
    bool bt (vector<vector<char>>& board, vector<pair<int, int>>& unfilled, int i) {
        
        if (i == unfilled.size()) {
            return true;
        }
        
        auto& [a, b] = unfilled[i];
        int c = 3 * (a / 3) + b/3;
        
        for (int j = 1; j <= 9; ++j) {
            int n = 1 << j;
            if ((rows[a] & n) || (cols[b] & n) || (boxs[c] & n)) continue;
            rows[a] |= n;
            cols[b] |= n;
            boxs[c] |= n;
            board[a][b] = '0' + j;
            if (bt(board, unfilled, i + 1)) return true;
            rows[a] ^= n;
            cols[b] ^= n;
            boxs[c] ^= n;
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {

        rows = cols = boxs = vector<int>(9, 0);
        
        vector<pair<int, int>> unfilled;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    unfilled.emplace_back(i, j);
                }
                else {
                    int n = 1 << board[i][j] - '0';
                    int k = (i/3) * (3) + j/3;
                    rows[i] |= n;
                    cols[j] |= n;
                    boxs[k] |= n;
                }
            }
        }
        
        bt(board, unfilled, 0);
    }
};