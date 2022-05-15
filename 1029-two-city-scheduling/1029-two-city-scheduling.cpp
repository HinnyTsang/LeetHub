class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto& a, auto& b) {
            return a[0] - a[1] < b[0] - b[1]; 
        });
        
        int total_cost = 0;
        
        for (int i = 0; i < costs.size()/2; ++i) {
            total_cost += costs[i][0];
        }
        
        for (int i = costs.size()/2; i < costs.size(); ++i) {
            total_cost += costs[i][1];
        }
        
        return total_cost;
    }
};