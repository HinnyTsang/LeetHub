class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        vector<int> bit_mask(words.size(), 0);
        
        int max_len = 0;
        
        for (int i = 0; i < words.size(); ++i) {
            
            for (auto& c: words[i]) {
                bit_mask[i] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; ++j) {
                if ((bit_mask[i] & bit_mask[j]) == 0) {
                    max_len = max(max_len, (int)(words[i].size() * words[j].size()));
                }
            }
        } 
        return max_len;
    }
};