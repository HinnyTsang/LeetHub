class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int curr = 0, prev = 0, result = 0;
        
        for (int i = 1; i < cost.size(); ++i) {
            result = min(curr + cost[i], prev + cost[i-1]);
            prev = curr;
            curr = result;
        }
        
        return result;
    }
};