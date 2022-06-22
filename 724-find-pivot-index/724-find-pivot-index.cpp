class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        
        for (int i = 1; i < n; ++i) {
            l[i] = nums[i-1] + l[i-1];
            r[n-i-1] = nums[n-i] + r[n-i]; 
        }
        
        for (int i = 0; i < n; ++i) {
            if (l[i] == r[i])
                return i;
        }
        
        return -1;
        
    }
};