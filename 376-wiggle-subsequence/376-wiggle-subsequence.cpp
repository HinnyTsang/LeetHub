class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> up(n, 1);
        vector<int> dw(n, 1);
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                up[i] = dw[i-1] + 1;
                dw[i] = dw[i-1];
            }
            else if (nums[i] < nums[i-1]) {
                up[i] = up[i-1];
                dw[i] = up[i-1] + 1;
            }
            else {
                up[i] = up[i-1];
                dw[i] = dw[i-1];
            }
        }
        
        return max(up.back(), dw.back());
    }
};