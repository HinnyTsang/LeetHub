class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int len_path = 1;
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> bfs;
        int neib [5] = {-1, 0, 1, 0, -1};
        
        maze[entrance[0]][entrance[1]] = '+';
        bfs.emplace(entrance[0], entrance[1]);
        
        while (bfs.size() > 0) {
            int l = bfs.size();
            while(l-- > 0) {
                auto [i, j] = bfs.front(); bfs.pop();
                for (int k = 0; k < 4; ++k) {
                    int a = i + neib[k];
                    int b = j + neib[k+1];
                    if (a < 0 || b < 0 || a == m || b == n || maze[a][b] == '+')
                        continue;
                    
                    if (a == 0 || b == 0 || a == m-1 || b == n - 1)
                        return len_path;
                    
                    maze[a][b] = '+';
                    bfs.emplace(a, b);
                }
            }
            ++len_path;
        }
        
        return -1;
    }
};