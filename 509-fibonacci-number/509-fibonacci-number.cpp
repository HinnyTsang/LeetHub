class Solution {
public:
    int fib(int n) {
        
        if (n == 0) return 0;
        
        int f0 = 0, f1 = 1, tmp = 1;
        
        while (n-- > 1) {
            tmp = f1;
            f1 += f0;
            f0 = tmp;
        }
        
        return f1;
    }
};