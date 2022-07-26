class Solution {
private:
    int binary_search(vector<int>& nums, int l, int r, const int &target);
    int search(vector<int>& nums, int l, int r, const int &target);
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
};


int Solution::search(vector<int>& nums, int l, int r, const int &target) {
    
    int m = l + ( r - l )/ 2;
    
    if (l == r) {
        return nums[l] == target? l: -1;
    }
    
    if (nums[l] < nums[r])
        return binary_search(nums, l, r, target);
    
    int a = search(nums, l, m, target);
    
    if (a != -1) return a;
    
    return search(nums, m+1, r, target);
}

int Solution::binary_search(vector<int>& nums, int l, int r, const int &target) {
    
    int m;
    
    while (l <= r) {
        m = l + (r - l)/2;
        
        if (nums[m] == target)
            return m;
        else if (nums[m] > target) 
            r = m - 1;
        else
            l = m + 1;        
    }
    return -1;
}