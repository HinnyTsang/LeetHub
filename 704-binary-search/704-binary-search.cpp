class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (i < 0 || i == nums.size())
            return -1;
        return nums[i] == target? i: -1;
    }
};