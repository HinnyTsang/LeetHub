struct Node {
    bool isEnd;
    string word;
    Node *next [26];
    Node(): isEnd(false), word("") {
        for (int i = 0; i < 26; ++i){
            next[i] = nullptr;
        }
    };
    
    ~Node() {
        for (int i = 0; i < 26; ++i) {
            delete next[i];
        }
    }
};


class Trie {
private:
    Node* head;
    void get_all (Node* w, vector<string>& res) {
        if (w->isEnd) {
            res.push_back(w->word);
        }
        else {
            for (int i = 0; i < 26; ++i) {
                if (w->next[i]) {
                    get_all(w->next[i], res);
                }
            }
        }
    }
public:
    Trie() {
        head = new Node();
    };
    ~Trie() {
        delete head ;
    }    
    
    void add_word(string& s) {
        Node* w = head;
        for (auto& c: s) {
            w->isEnd = false;
            w->word = "";
            if (!w->next[c - 'a']) {
                w->next[c - 'a'] = new Node();
            }
            w = w->next[c - 'a'];
        }
        
        for (int i = 0; i < 26; ++i) {
            if (w->next[i])
                return;
        }
        
        w->isEnd = true;
        w->word = s;
    }
    
    vector<string> get_words() {
        vector<string> result;
        get_all(head, result);
        return result;
    }
};


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        Trie* trie = new Trie();
        
        for (string& w: words) {
            reverse(w.begin(), w.end());
            trie->add_word(w);
        }
        
        vector<string> keep = trie->get_words();
        int result = 0;
        
        for (auto& s: keep) {
            result += s.size() + 1;
        }
        
        return result;
    };
};