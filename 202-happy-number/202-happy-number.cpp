class Solution {
private:
    const bool HAPPY = true;
    const bool UNHAPPY = false;
    
public:
    bool isHappy(int n) {
        
        bool *seen = new bool [10]();
        
        while (n != 1) {
        
            int m = 0;
            
            while (n > 0) {
                m += (n % 10) * (n % 10);
                n /= 10;
            }
            
            n = m;
            
            if (n < 10 && seen[n])
                return false;
            
            if (n < 10) 
                seen[n] = true;
        }
        
        return n == 1 ? HAPPY: UNHAPPY;
    }
};