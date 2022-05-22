class Solution {
    int neib [5] = {1, 0, -1, 0, 1};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int oldColor = image[sr][sc];
        int nr = image.size(), nc = image[0].size();
        
        queue<pair<int, int>> bfs;
        
        if (oldColor != newColor) bfs.emplace(sr, sc);
        
        while (!bfs.empty()) {
            int n = bfs.size();
            while (n--) {
                auto [i, j] = bfs.front(); bfs.pop();
                image[i][j] = newColor;
                
                for (int k = 0; k < 4; ++k) {
                    int a = i + neib[k];
                    int b = j + neib[k+1];
                    
                    if (a < 0 || b < 0 || a == nr || b == nc || image[a][b] != oldColor)
                        continue;
                    
                    bfs.emplace(a, b);
                }
            }
        }
        
        return image;
    }
};