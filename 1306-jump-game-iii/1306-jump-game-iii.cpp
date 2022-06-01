class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> seen(n, false);
        queue<int> bfs;
        
        bfs.push(start);
        seen[start] = true;
        
        
        while (bfs.size() > 0) {
            int l = bfs.size();
            while (l-- > 0) {
                int c = bfs.front(); bfs.pop();
                if (arr[c] == 0)
                    return true;
                
                if (c + arr[c] < n && !seen[c + arr[c]]) {
                    bfs.push(c + arr[c]);
                    seen[c + arr[c]] = true;
                }
                if (c - arr[c] >= 0 && !seen[c - arr[c]]) {
                    bfs.push(c - arr[c]);
                    seen[c - arr[c]] = true;
                }
            }
        }
        
        return false;
    }
};