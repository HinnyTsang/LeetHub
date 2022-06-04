class Solution {
private:
    bool dfs(int i, vector<vector<int>>& graph, vector<int>& group, int color) {
        if (group[i] == -1) {
            group[i] = color;
            for (auto& nxt: graph[i]) {
                if (!dfs(nxt, graph, group, (color + 1)%2)) 
                    return false;
            }
            return true;
        }
        else if (group[i] != color)
            return false;
        
        return true;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // identical to color problem.
        
        vector<int> group(n, -1);
        vector<vector<int>> graph(n);
        
        for (auto& edge: dislikes) {
            graph[edge[0]-1].push_back(edge[1]-1);
            graph[edge[1]-1].push_back(edge[0]-1);
        }
        
        for (int i = 0; i < n; ++i) {
            if (group[i] != -1)
                continue;
            if (!dfs(i, graph, group, 1))
                return false;
        }
        
        return true;
    }
};