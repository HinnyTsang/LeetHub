class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> seen;
        queue<string> bfs;
        string start = "0000";
        int count_moves = 0;
        
        for (auto& deadend: deadends)
            seen.insert(deadend);
        
        if (seen.count(start)) return -1;
        
        bfs.push(start);
        seen.insert(start);        
        
        while (!bfs.empty()) {
            
            int n = bfs.size(); 
            
            while (n-- > 0) {
                
                string curr = bfs.front(); bfs.pop();
                
                if (curr == target)
                    
                    return count_moves;
                
                for (int i = 0; i < 4; ++i) {
                    
                    char tmp = curr[i];
                    char l   = curr[i] - 1;
                    char r   = curr[i] + 1;
                    
                    l = l < '0'? '9': l;
                    r = r > '9'? '0': r;
                    
                    for (char c: {l, r}) {
                        curr[i] = c;
                        if (!seen.count(curr)) {
                            bfs.push(curr);
                            seen.insert(curr);
                        }
                    }
                    curr[i] = tmp;
                    
                }
            }
        
            ++count_moves;
        }    
        return -1;
    }
};