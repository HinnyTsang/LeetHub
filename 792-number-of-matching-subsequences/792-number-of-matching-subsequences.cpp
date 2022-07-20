class Solution {
private:
    
    bool is_subseq(vector<vector<int>>& hash, string& word) {
        
        if (hash[word[0] - 'a'].size() == 0 )
            return false;
        
        int idx = hash[word[0] - 'a'][0];
        
        for (int i = 1; i < word.size(); ++i) {
            if (hash[word[i] - 'a'].size() == 0)
                return false;
            auto lower = lower_bound(hash[word[i] - 'a'].begin(), hash[word[i] - 'a'].end(), idx + 1);
            if (lower == hash[word[i] - 'a'].end())
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