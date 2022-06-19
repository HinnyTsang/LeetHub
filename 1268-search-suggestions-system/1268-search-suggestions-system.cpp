struct TrieNode {
    bool isEnd;
    string word;
    TrieNode* next[26];
    TrieNode (): isEnd(false), word("") {
        for (int i = 0; i < 26; ++i)
            next[i] = nullptr;
    }
    ~TrieNode () {
        for (int i = 0; i < 26; ++i)
            delete next[i];
    }
};

class Trie {
private:
    TrieNode* head;
public:
    Trie () {
        head = new TrieNode();
    }
    
    TrieNode* getHead() {
        return head;
    }
    
    void add(string& s) {
        
        TrieNode* w = head;
        
        for (char& c: s) {
            if (w->next[c-'a'] == nullptr) {
                w->next[c-'a'] = new TrieNode();
            }
            w = w->next[c-'a'];
        }
        w->isEnd = true;
        w->word = s;
    }
};

class Solution {
private:
    void search(TrieNode* w, vector<string>& result) {
        if (result.size() == 3)
            return;
        
        if (w->isEnd) {
            result.push_back(w->word);
        }
        for (int i = 0; i < 26; ++i) {
            if (w->next[i]) {
                search(w->next[i], result);
            }
        }
    }
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        Trie* root = new Trie();
        
        for (auto& prod: products) {
            root->add(prod);
        }
        
        int n = searchWord.size();
        vector<vector<string>> result(n, vector<string>());
        
        TrieNode* w = root->getHead();
        
        for (int i = 0; i < n; ++i) {
            auto& c = searchWord[i];
            if (w->next[c - 'a']) {                
                w = w->next[c - 'a'];
                search(w, result[i]);
            }
            else {
                return result;
            }
        }
        
        return result;
    }
};