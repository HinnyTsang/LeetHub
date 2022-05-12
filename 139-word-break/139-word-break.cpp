class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> dict(wordDict.begin(), wordDict.end());
        // dp
        bool* dp = new bool [s.size() + 1] ();
        // index for starting points.
        vector<int> st_idx(1, 0);
        
        int max_len;
        // for the ending criteria
        for (auto& word: dict)
            max_len = max(max_len, (int)word.size());
        
        
        for (int r = 0; r <= s.size(); ++r) {

            for (int i = st_idx.size() - 1; i >= 0  && !dp[r]; --i) {
                // left index of the substr.

                int l = st_idx[i];
                
                if (dict.count(s.substr(l, r - l+1))) {
                    dp[r] = true;
                    st_idx.push_back(r + 1);
                }
            }
        }
        
        return dp[s.size()];
    }
};