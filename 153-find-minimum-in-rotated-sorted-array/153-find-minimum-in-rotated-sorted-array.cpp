class Solution {
    int search(vector<int>& nums, int l, int r) {
        if (r == l) return nums[l];
        
        if (nums[l] < nums[r]) 
            return nums[l];
        
        int m = l + (r - l)/2;
        
        return min(search(nums, l, m), search(nums, m+1, r));
    }
public:
    int findMin(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);
    }
};