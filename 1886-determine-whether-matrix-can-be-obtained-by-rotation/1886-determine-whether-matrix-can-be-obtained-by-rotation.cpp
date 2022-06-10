class Solution {
private:
    
    void rotate(vector<vector<int>>& mat) {
        reverse(mat.begin(), mat.end());
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = i + 1; j < mat.size(); ++j) {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
    
    bool compare(vector<vector<int>>& m1, vector<vector<int>>& m2) {
        
        int n = m1.size(); 
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (m1[i][j] != m2[i][j])
                    return false;
            }
        }
        return true;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; ++i) {
            if (compare(mat, target))
                return true;
            rotate(mat);
        }
        return false;
    }
};