class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> in(n, 0), out(n, 0);
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        int max_rank = 0;
        
        for (auto& road: roads) {
            ++in[road[1]], ++in[road[0]];
            graph[road[0]][road[1]] = graph[road[1]][road[0]] = true;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = in[i] + in[j] + (graph[i][j] ? -1: 0);
                max_rank = max(max_rank, rank);
            }
        }
        return max_rank;
    }
};