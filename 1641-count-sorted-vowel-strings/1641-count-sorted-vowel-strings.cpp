class Solution {
public:
    int countVowelStrings(int n) {
        /**
         *  a e i o u
         *  1 1 1 1 1 -> 5
         *  5 4 3 2 1 -> 15 = 5*5 - 4 - 3 - 2 - 1
         *  15 (15-5) (15-5-4) (15-5-4-3) (15-5-4-3-2) -> 15 * 5 - 5 * 4 - 4 * 3 - 3 * 2 - 2
         *  (k) (k - (ka)) + (k - ka - ke) + (k - ka - ke - ki) + (k - ka - ke - ki -ko)
         *  k_new = k * 5 - ka * 4 - ke * 3 - ki * 2 - ko
         */
        
        int k [2][5] = {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
        int result = 5;
        
        while (n-- > 1) {
            
            for (int i = 0; i < 5; ++i) {
                k[1][i] = i == 0? result: k[1][i-1] - k[0][i-1];
                
            }
            result = 0;
            for (int i = 0; i < 5; ++i) {
                k[0][i] = k[1][i];
                result += k[1][i];
            }
            
        }
        
        return result;
    }
};