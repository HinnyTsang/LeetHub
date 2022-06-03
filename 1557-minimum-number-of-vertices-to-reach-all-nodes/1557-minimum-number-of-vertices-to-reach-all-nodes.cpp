class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        int *in_deg = new int [n]();
        vector<int> result;
        
        for (auto& edge: edges) {
            ++in_deg[edge[1]];
        }
        
        for (int i = 0; i < n; ++i) {
            if (in_deg[i] == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};