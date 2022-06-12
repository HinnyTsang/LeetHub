class Solution {
private:
    int n;
    int res;
    void backtracking (vector<int>& cookies, vector<int>& buckets, int i, int k) {
        if (i == n) {
            res = min(res, *max_element(buckets.begin(), buckets.end()));
        }
        
        else {
            for (int j = 0; j < k; ++j) {
                if (buckets[j] + cookies[i] > res) {
                     continue;
                }
                buckets[j] += cookies[i];
                backtracking(cookies, buckets, i+1, k);
                buckets[j] -= cookies[i];                
            }
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        res = INT_MAX;
        vector<int> buckets(k, 0);
        backtracking(cookies, buckets, 0, k);
        return res;
    }
};