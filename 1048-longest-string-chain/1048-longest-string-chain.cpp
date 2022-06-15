class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(),  [](auto&a, auto& b) {return a.size() < b.size(); });
        unordered_map<string, int> pre;
        int result = 1;
                
        for (int i = 0; i < words.size(); ++i) {
            string& s = words[i];
            pre[s] = 1;
            // cout << s << endl;
            for (int j = 1; j <= s.size(); ++j) {
                string curr = s.substr(0, max(0, j-1)) + s.substr(j);
                if (pre.count(curr)) {
                    pre[s] = max(pre[s], pre[curr] + 1);
                    result = max(result, pre[s]);
                }
            }
        }
        
        
        return result;
    }
};