class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if (s.size() < p.size()) return {};
        
        vector<int> store(26, 0), curr(26, 0), res;
        
        int r = 0, l = 0;
        
        for (auto& c: p) {
            ++store[c - 'a'];
        }
        for (; r < p.size() ; ++r) {
            ++curr[s[r] - 'a'];
        }
        
        if(curr == store) res.push_back(l);
        
        for (; r < s.size(); ++r) {
            --curr[s[l++] - 'a'];
            ++curr[s[r] - 'a'];
            // for (auto& i: curr)
            //     cout << i << ' ';
            // cout << endl;
            if (curr == store) res.push_back(l);
        }
        
        return res;
    }
};