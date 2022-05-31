class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        unordered_set<string> comb;
        int n = s.size() - k + 1;
        
        for (int i = 0; i < n; ++i) {
            comb.insert(s.substr(i, k));
        }
        
        return comb.empty()? false: comb.size() == pow(2, k);
    }
};