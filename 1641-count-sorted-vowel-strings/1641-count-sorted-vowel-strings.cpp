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
        
        int k_each [5] = {1, 1, 1, 1, 1};
        int  k_new [5] = {1, 1, 1, 1, 1};
        int result = 5;
        
        while (n-- > 1) {
            
            k_new[0] = result;
            k_new[1] = k_new[0] - k_each[0];
            k_new[2] = k_new[1] - k_each[1];
            k_new[3] = k_new[2] - k_each[2];
            k_new[4] = k_new[3] - k_each[3];
            
            result = 0;
            for (int i = 0; i < 5; ++i)
                result += k_new[i], k_each[i] = k_new[i];

        }
        
        return result;
    }
};