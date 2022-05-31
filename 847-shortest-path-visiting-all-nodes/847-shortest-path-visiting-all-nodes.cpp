typedef pair<int, int> pii;


struct hash_func
{
  size_t operator()(const pair<int , 
                    int> &x) const
  {
    return x.first ^ x.second;
  }
};

class Solution {

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        int complete = (1 << n) - 1; // mask for the path visited every nodes.
        
        // curr, bit mask.
        queue<pii> bfs;
        // curr, bit mask
        vector<vector<bool>> seen_path(complete + 1, vector<bool>(n, false));
        // cost
        int cost_counter = 0;
        
        // since we don't know which one is the best start point.
        for (int i = 0; i < n; ++i) {
            int mask = 1 << i;
            bfs.emplace(i, mask);
            seen_path[mask][i] = true;
        }
        
        while (bfs.size() > 0) {
            
            int l = bfs.size();
            
            while (l-- > 0) {
                
                auto [curr, mask] = bfs.front(); bfs.pop();
                
                if (mask == complete)  {
                    return cost_counter;
                }
                
                for (int node: graph[curr]) {
                    int next_mask = mask | (1 << node);
                    
                    if (seen_path[mask][node]) 
                        continue;
                    
                    bfs.emplace(node, next_mask);
                    seen_path[mask][node] = true;
                }
            }
            
            ++cost_counter;
        }
        return -1;
    }
};