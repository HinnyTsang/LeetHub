class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        
        int up = 1, dw = 1;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                up = dw + 1;
            else if (nums[i] < nums[i-1])
                dw = up + 1;
        }
        
        return max(dw, up);
    }
};