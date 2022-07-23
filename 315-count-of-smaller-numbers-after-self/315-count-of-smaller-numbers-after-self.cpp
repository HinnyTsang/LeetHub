class Solution {
private:
    void merge_sort(vector<pair<int, int*>>& nums, int l, int r) {
        if (l == r)
            return;
        
        int m = (l + r)/2, cum = 0;
        
        merge_sort(nums, l, m);
        merge_sort(nums, m+1, r);
        
        vector<pair<int, int*>>temp(r - l + 1);

        for (int i = l, j = m+1, k = 0; k < temp.size(); ++k) {
            if (i <= m && j <= r) {
                if (nums[i].first <= nums[j].first) {
                    temp[k] = nums[i++];
                    *(temp[k].second) += j - m - 1;
                }
                else {
                    temp[k] = nums[j++];
                }
            }
            else if (i <= m) {
                
                temp[k] = nums[i++];
                *(temp[k].second) += j - m - 1;
            }
            else if (j <= r) {
                temp[k] = nums[j++];
            }
        }
        
        for (int i = 0, j = l; i < temp.size(); ++i, ++l) {
            nums[l] = temp[i];
        }
        
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<pair<int, int*>> temp(n);
        
        for (int i = 0; i < n; ++i) {
            temp[i].first = nums[i];
            temp[i].second = &result[i];
        }
        
        merge_sort(temp, 0, n - 1);
        
        return result;
    };
    vector<int> countSmaller_TLE(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> big;
        priority_queue<int, vector<int>, less<int>> small;
        int n = nums.size();
        vector<int> result(n, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            while (!small.empty() && small.top() >= nums[i]) {
                big.push(small.top());
                small.pop();
            }
            while (!big.empty() && big.top() < nums[i]) {
                small.push(big.top());
                big.pop();
            }
            result[i] = small.size();
            
            small.push(nums[i]);
        }
        return result;
    }
};