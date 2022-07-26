class Solution {
private:
    bool matched(unordered_map<char, int>& a, unordered_map<char, int>& b) {
        
        for (auto& [key, cnt]: b) {
            if (a[key] < cnt)
                return false;
        }
        
        return true;
    }
public:
    string minWindow(string s, string t) {
        
        
        string result;
        unordered_map<char, int> char_count;        
        unordered_map<char, int> to_check;        
        int l = 0, r = 0, len = INT_MAX;
        
        if (t.size() > s.size()) return result;
        
        for (char& c: t) ++to_check[c];
        
        for (int r = 0; r < s.size(); ++r) {
            
            ++char_count[s[r]];
            
            while (l <= r && char_count[s[l]] > to_check[s[l]]) {
                --char_count[s[l++]];
            }
            
            if (matched(char_count, to_check) && r - l + 1 < len) {
                result = s.substr(l, r - l + 1);
                len = r - l + 1;
            }
        }
        
        return result;
        
    }
};