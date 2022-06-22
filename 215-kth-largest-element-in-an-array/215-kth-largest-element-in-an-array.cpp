class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> largest;
        
        for (int& num: nums) {
            largest.push(num);
            if (largest.size() > k) {
                largest.pop();
            }
        }
        
        return largest.top();
    }
};