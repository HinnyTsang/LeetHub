class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int l = 0, r = 0, operations = INT_MAX;
        
        while ( r >= l ) {
            if (sum < x) {
                sum += nums[l++];   
            }
            else {
                
                if (sum == x) {
                    operations = min(operations, n - r + l);
                }
                
                if (r < n)
                    sum -= nums[r++];
                else
                    break;
            }
        }
        
        return operations == INT_MAX ? -1: operations;
    }
};