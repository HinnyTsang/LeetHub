class Solution {
private:
    void dfs(vector<vector<int>>& image, int i, int j, const int &ori, const int &col) {
        
        if (i < 0 || j < 0 || i == image.size() || j == image[0].size() || image[i][j] != ori)
            return;
        
        image[i][j] = col;
        dfs(image, i, j+1, ori, col);
        dfs(image, i, j-1, ori, col);
        dfs(image, i+1, j, ori, col);
        dfs(image, i-1, j, ori, col);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ori = image[sr][sc];
        
        if (ori == color)
            return image;
        
        dfs(image, sr, sc, ori, color);
        
        return image;
    }
};