class Solution {
public:
    int minDeletions(string s) {
        vector<int> char_count(26, 0);
        unordered_set<int> freq;
        int result = 0;
        
        for (auto& c: s) {
            ++char_count[c - 'a'];
        }
        
        
        for (int i = 0; i < 26; ++i) {
            if (char_count[i] == 0)
                continue;
            while (char_count[i] > 0 && freq.count(char_count[i])) {
                --char_count[i];
                ++result;
            }
            freq.insert(char_count[i]);
        }
        
        return result;
        
    }
};