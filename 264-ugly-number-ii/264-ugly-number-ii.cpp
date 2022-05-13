class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> result(1, 1);
        
        int i = 0, j = 0, k = 0;
        
        while (n-- > 1) {
            result.push_back(min({2*result[i], 3*result[j], 5*result[k]}));
            
            if (result.back() == 2*result[i]) ++i;
            
            if (result.back() == 3*result[j]) ++j;
            
            if (result.back() == 5*result[k]) ++k;
        }
        
        return result.back();
    }
};