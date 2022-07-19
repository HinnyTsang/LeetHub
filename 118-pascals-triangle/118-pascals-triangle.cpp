class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for (int i = 1; i <= numRows; ++i) {
            
            vector<int> row(i, 1);
            
            result.push_back(row);
            
            for (int j = 1; j < i - 1; ++j) {
                result.back()[j] = result[i-2][j-1] + result[i-2][j];
            }
        }
        return result;
    }
};