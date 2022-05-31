class Solution {
    void dfs(vector<vector<int>>& next_graph, vector<vector<int>>& curr_graph, vector<int>& next_len, vector<int>& curr_len, int i) {
        
        for (int j: next_graph[i]) {
            if (next_len[j] != -1 && next_len[j] < curr_len[i] + 1)
                continue;
            // cout << i << "->" << j << endl;
            next_len[j] = curr_len[i] + 1;
            dfs(curr_graph, next_graph, curr_len, next_len, j);
        }
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<int>> bg(n), rg(n);
        vector<int> blen(n, -1), rlen(n, -1);        
        
        blen[0] = rlen[0] = 0;
        
        for (auto& e: redEdges) {
            rg[e[0]].push_back(e[1]);
        }
        for (auto& e: blueEdges) {
            bg[e[0]].push_back(e[1]);
        }
        
        dfs(bg, rg, blen, rlen, 0);
        dfs(rg, bg, rlen, blen, 0);
        
        for (int i = 0; i < n; ++i) {
            rlen[i] = rlen[i] == -1? blen[i] : blen[i] == -1 ? rlen[i]: min(rlen[i], blen[i]);
        }
        
        return rlen;
    }
};