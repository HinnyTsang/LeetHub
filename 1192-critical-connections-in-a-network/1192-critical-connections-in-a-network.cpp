class Solution {
private:
    void dfs(vector<vector<int>>& result, vector<bool>& visited, vector<int>& lowest_rank, vector<vector<int>>& graph, int curr_rank, int prev, int curr) {
        
        // update visited and initialize current rank (distance from the starting node).
        visited[curr] = true;
        lowest_rank[curr] = curr_rank;
        
        // loop throught next nodes.
        for (int next: graph[curr]) {
            
            // preventing infinite loop
            if (next == prev)
                continue;
            
            if (!visited[next]) {
                dfs (result, visited, lowest_rank, graph, curr_rank + 1, curr, next);
            }            
            // update lowest_rank of current node.
            lowest_rank[curr] = min(lowest_rank[curr], lowest_rank[next]);
            
            // if the next node is not updated (can't go back to the previous chacked node),
            // the next node is singlely connected with curr node.
            if (lowest_rank[next] > curr_rank)
                result.push_back({curr, next});
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<bool> visited(n, false);
        vector<int> lowest_rank(n, INT_MAX);
        vector<vector<int>> result;
        vector<vector<int>> graph(n);
        
        // current rank value;
        int curr_rank = 0;
        
        // default value of rank.
        for (int i = 0; i < n; ++i)
            lowest_rank[i] = i;
        
        // fill the graph.
        for (auto& edge: connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // dfs
        dfs (result, visited, lowest_rank, graph, curr_rank, 0, 0);
        
        return result;
    }
};