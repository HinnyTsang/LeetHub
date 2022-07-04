class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = 0, curr = 0, min_cost = min(cost[0], cost[1]);
        
        for (int i = 1; i < cost.size(); ++i) {
            min_cost = min(curr + cost[i], prev + cost[i - 1]);
            prev = curr;
            curr = min_cost;
        }
        return min_cost;
    }
};