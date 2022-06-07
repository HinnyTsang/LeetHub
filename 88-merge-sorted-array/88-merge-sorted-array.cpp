class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        
        for (int l = m + n -1; l >= 0; --l) {
            if (j < 0) break;
            else if (i < 0) {
                nums1[l] = nums2[j--];
            }
            else {
                if (nums1[i] > nums2[j]) {
                    nums1[l] = nums1[i--];
                }
                else {
                    nums1[l] = nums2[j--];
                }
            }
        }
    }
};