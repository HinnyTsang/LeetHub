


class Trie {
private:
    struct TrieNode {
        bool isEnd;
        vector<TrieNode*> next;
        TrieNode(): isEnd(false) {
            next = vector<TrieNode*>(26, nullptr);
        };
    };
    TrieNode* head;
    
public:
    Trie() {
        head = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* work = head;
        
        for (char& c: word) {
            if (!work->next[c-'a'])
                work->next[c-'a'] = new TrieNode();
            work = work->next[c-'a'];
        }
        work->isEnd = true;
    }
    
    bool search(string word) {
        
        TrieNode* work = head;
        
        for (char& c: word) {
            if (!work->next[c-'a'])
                return false;
            work = work->next[c-'a'];
        }
        return work->isEnd;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* work = head;
        
        for (char& c: prefix) {
            if (!work->next[c-'a'])
                return false;
            work = work->next[c-'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */