class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        unordered_set<int> seen;
        unordered_map<int, vector<int>> station_to_route;
        queue<int> curr;
        int result = 1;
        
        if (source == target) return 0;
        
        for (int route = 0; route < n; ++route) {
            for (int i: routes[route]) {
                station_to_route[i].push_back(route);
            }
        }
        
        for (auto& route: station_to_route[source]) {
            curr.emplace(route);
        }
        seen.insert(source);
        
        while(!curr.empty()) {
        
            int m = curr.size(); 
            
            while (m-- > 0) {
                int route = curr.front(); 
                curr.pop();
                
                for (int loc: routes[route]) {
                    if (loc == target)
                        return result;
                    
                    if (seen.count(loc))
                        continue;
                    
                    seen.count(loc);
                    for (int next_bus: station_to_route[loc]) {
                        curr.push(next_bus);
                    }
                    
                }
                routes[route].clear();
            }
            ++result;
        }
        
            
        return -1;
    }
};