class Solution {
public:
    int integerBreak(int n) {
        
        if (n < 4) return n - 1;
        
        int result = 1;
        
        while (n) {
            if (n == 4 || n == 2) {
                result *= n;
                n -= n;
            }
            else {
                result *= 3;
                n -= 3;
            }
        }
        
        return result;
    }
};