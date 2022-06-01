class Solution {
private:
    
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        // pos, [forward, backword]
        vector<pair<bool, bool>> seen(10000, pair<bool, bool>(false, false));
        // It cannot jump backward twice in a row.
        queue<pair<int, bool>> bfs; // pos, is_backword.
        
        for (auto& i: forbidden) {
            seen[i] = pair<bool, bool>(true, true);
        }
        
        if (seen[0].first && seen[0].second) return -1;
        // bfs.push(0);
        bfs.push(pair<int, bool>(0, false)); 
        seen[0] = pair<bool, bool>(true, true);
        
        int steps = 0;
        
        while (bfs.size()) {
            int n = bfs.size();             
            
            while (n-- > 0) {
                
                auto [curr, is_backword] = bfs.front(); 
                bfs.pop();
                
                if (curr == x) return steps;
                
                int l = curr + a, r = curr - b;
                
                if ( l < 10000 && !seen[l].first) {
                    bfs.emplace(l, false);
                    seen[l].first = true;
                }
                
                if (!is_backword && r >= 0 && !seen[r].second) {
                    bfs.emplace(r, true);
                    seen[r].second = true;
                }
            }
            ++steps;
        }
        return -1;
    }
};