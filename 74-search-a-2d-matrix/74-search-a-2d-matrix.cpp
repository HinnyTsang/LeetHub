class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        
        auto row = lower_bound(matrix.begin(), matrix.end(), target, [](const vector<int>& r, const int& target) {
            return r[0] <= target;
        }) - matrix.begin();
        
        --row;
        
        if (target < matrix[row][0] || target > matrix[row].back()) return false;
        
        auto col = lower_bound(matrix[row].begin(), matrix[row].end(), target) - matrix[row].begin();
        
        return matrix[row][col] == target;
    }
};