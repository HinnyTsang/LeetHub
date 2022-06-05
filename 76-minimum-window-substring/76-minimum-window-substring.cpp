class Solution {
private:
    bool is_subset(unordered_map<char, int>& all, unordered_map<char, int>& sub) {
        for (auto& [key, val]: all) {
            if (!sub.count(key) || sub[key] < val)
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        
        unordered_map<char, int> wct, window;
        int l = 0, r = 0, min_length = INT_MAX, start = -1;
        
        for (auto& c: t) {
            ++wct[c];
        }
        
        for (;r < s.size(); ++r) {
            ++window[s[r]];
            
            if (wct.count(s[r]) && is_subset(wct, window)) {
                while (!wct.count(s[l]) || window[s[l]] > wct[s[l]]) {
                    --window[s[l++]];
                }
                int len = r - l + 1;
                if (len < min_length) {
                    min_length = len;
                    start = l;
                }
            }
        }
        
        return start == -1? "": s.substr(start, min_length);
    }
};