class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        
        vector<long long> bit_count(30, 0);
        unordered_set<int> n(nums.begin(), nums.end());
        long long result = 0;
        
        for (int i: n) {
            ++bit_count[__builtin_popcount(i)];
        }
        
        for (int i = 1; i < 30; ++i) {
            for (int j = max(i, k-i); j < 30; ++j) {
                
                result += i==j? bit_count[i]*bit_count[j]: 2 * bit_count[i]*bit_count[j];
            }
        }
        
        return result;
    }
};