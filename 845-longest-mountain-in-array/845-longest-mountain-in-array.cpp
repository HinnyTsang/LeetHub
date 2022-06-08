class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int l = 0, r = 0;
        int longest = 0;
        
        for (int i = 1; i < arr.size(); ++i ){
            if (arr[i] > arr[i-1]) {
                if (r > 0) {
                    l = r = 0;
                }
                ++l;
            }
            else if (arr[i] < arr[i-1]) {
                if (l > 0) {
                    ++r;
                    longest = max(longest, l + r + 1);
                }
            }
            else {
                l = r = 0;
            }
            // cout << arr[i] << ": " << l << ", "<< r << endl;
        }
        
        return longest;
    }
};