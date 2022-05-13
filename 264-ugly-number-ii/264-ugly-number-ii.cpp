class Solution {
public:
    int nthUglyNumber(int n) {
        
        int *result = new int [n]();
        
        result[0] = 1;
        
        int i = 0, j = 0, k = 0;
        
        for (int x = 1; x < n; ++x) {
            result[x] = min({2*result[i], 3*result[j], 5*result[k]});
            
            if (result[x] == 2*result[i]) ++i;
            
            if (result[x] == 3*result[j]) ++j;
            
            if (result[x] == 5*result[k]) ++k;
        }
        
        return result[n-1];
    }
};