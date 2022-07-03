class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> ppl(forget, 0);
        int result = 0;
        ppl.back() = 1;
        
        for (int i = 1; i < n; ++i ){
            /**
             *  0 0 0 1  i = 0
             *  0 0 1 0  i = 1
             *  0 1 0 1  i = 2
             *  1 0 1 1  i = 3
             *  0 1 1 1  i = 4
             *  1 1 1 2  i = 5
             */
            ppl.erase(ppl.begin());
            
            int new_ppl = 0;
            
            for (int j = 0; j < forget - delay; ++j) {
                new_ppl += ppl[j];
                new_ppl %= 1000000007;
            }
            
            ppl.push_back(new_ppl);
        }
        
        for (int& p: ppl) {
            result += p;
            result %= 1000000007;
        }
        
        return result;
    }
};