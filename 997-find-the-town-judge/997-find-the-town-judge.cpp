class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        int *in_deg = new int [n+1]();
        int *out_deg = new int [n+1]();
        
        for (auto& item: trust) {
            ++in_deg[item[1]];
            ++out_deg[item[0]];
        }
        
        for (int i = 1; i <= n; ++i) {
            if (in_deg[i] == n - 1 && out_deg[i] == 0)
                return i;
        }
        
        return -1;
    }
};