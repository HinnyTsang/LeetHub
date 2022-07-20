class Solution {
private:
    
    bool is_subseq(vector<vector<int>>& hash, string& word) {
        
        if (hash[word[0] - 'a'].size() == 0 )
            return false;
        
        int idx = hash[word[0] - 'a'][0];
        
        for (int i = 1; i < word.size(); ++i) {
            
            auto& curr = hash[word[i] - 'a'];
            
            if (curr.size() == 0)
                return false;
            
            auto lower = lower_bound(curr.begin(), curr.end(), idx + 1);
            
            if (lower == curr.end())
                return false;
            
            idx = *lower;
        }        
        return true;
    }
    
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int result = 0;
        
        vector<vector<int>> hash(26);
        
        for (int i = 0; i < s.size(); ++i) {
            hash[s[i] - 'a'].push_back(i);
        }
        
        for (auto& word: words) {
            if (is_subseq(hash, word))
                ++result;
        }
        
        return result;
    }
};