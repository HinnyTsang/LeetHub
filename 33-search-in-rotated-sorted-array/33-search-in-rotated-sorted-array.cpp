class Solution {
private:
    int binary_search(vector<int>& nums, int& target, int l, int r) {
        if (r < l) 
            return -1;
        if (r == l) 
            return nums[l] == target ? l: -1;
        
        int m;
        
        while (r >= l) {
            m = l + (r - l)/2;
            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return -1;
    }
    int search(vector<int>& nums, int& target, int l, int r) {
        
        if (r < l) 
            return -1;
        if (r == l) 
            return nums[l] == target ? l: -1;
        
        if (nums[r] > nums[l])
            return binary_search(nums, target, l, r);
        
        int m = l + (r - l) / 2;
        
        if (nums[m] == target)
            return m;
        
        return 
            search(nums, target, l, m - 1) != -1?
            search(nums, target, l, m - 1):
            search(nums, target, m + 1, r);
    }
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
};