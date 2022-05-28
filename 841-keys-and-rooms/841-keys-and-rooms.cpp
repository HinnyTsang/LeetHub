class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        
        bool *seen = new bool [n] ();
        
        queue<int> bfs;
        
        bfs.push(0);
        
        while (bfs.size() > 0) {
            
            int l = bfs.size();
            
            while (l-- > 0) {
                
                int i = bfs.front(); bfs.pop();
                seen[i] = true;
                
                for (int j: rooms[i]) {
                    
                    if (seen[j]) continue;
                    bfs.push(j);
                    
                }    
            }
        }
        
        
        for (int i = 1; i < n; ++i) {
            if (!seen[i]) return false;
        }
        return true;
    }
};