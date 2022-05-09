class Solution {
private:
    unordered_map<char, vector<char>> mapping = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };
        
    void helper (string& digits, int i, vector<string>& result, string& work) {
        
        if (i == digits.size()) {
            result.push_back(work);
            return;
        }
            
        for (auto& c: mapping[digits[i]]) {
            work += c;
            helper(digits, i+1, result, work);
            work.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        
        vector<string> result;
        string work;
        
        if (digits.size() == 0) return result;
        
        helper(digits, 0, result, work);
        
        return result;
    }
};