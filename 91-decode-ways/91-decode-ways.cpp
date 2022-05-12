class Solution {
public:
    int numDecodings(string s) {
        
        // no way to decode.
        if (s[0] == '0') return 0;
        
        // number of ways to decode the substr s[0:i]
        int prev = 1, curr = 1;
        
        for (int r = 1; r < s.size(); ++r) {
            int temp = curr;

            curr = s[r] == '0'? 0: curr;
            
            if (s[r - 1] == '1' || s[r - 1] == '2') {
                curr += s[r - 1] == '1' ? prev : s[r] <= '6' ? prev: 0;
            }
            // no way to encode.
            prev = temp;
        }
        
        
        return curr;
    }
};