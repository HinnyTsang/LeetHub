class WordFilter {
private:
    unordered_map<string, int> pfxsfx;
public:
    WordFilter(vector<string>& words) {
        
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 1; j <= words[i].size(); ++j) {
                
                string pfx = words[i].substr(0, j);
                for (int k = words[i].size() - 1; k >= 0; --k) {
                    
                    string sfx = words[i].substr(k);
                    pfxsfx[pfx + '|' + sfx] = i;
                }
            }
        }
        
    }
    
    int f(string prefix, string suffix) {
        string pxsx = prefix + '|' + suffix;
        if (pfxsfx.count(pxsx))
            return pfxsfx[pxsx];
        else
            return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */