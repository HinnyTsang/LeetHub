class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> seen;
        int result = 0;
        for (int& n: nums) {
            if (seen.count(n)) {
                result += seen[n];
            }
            ++seen[n];
        }
        
        return result;
    }
};