class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& managers, vector<int>& informTime) {
        
        vector<vector<int>> children(n, vector<int>());
        queue<int> manager;
        int max_time = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i == headID) continue;
            
            if (managers[i] == headID) {
                informTime[i] += informTime[headID];
                manager.push(i);
                max_time = max(max_time, informTime[i]);
            }
            else {
                children[managers[i]].push_back(i);
            }   
        }
        
        while (manager.size() > 0) {
            int l = manager.size();
            
            while (l-- > 0) {
                int employee = manager.front(); manager.pop();
                
                for (auto& i: children[employee]) {
                    informTime[i] += informTime[employee];
                    manager.push(i);
                    max_time = max(max_time, informTime[i]);
                }
            }
        }
        
        return max_time;
    }
};