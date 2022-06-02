class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, bool> seen;
        queue<string> bfs;
        int n_transform = 1;
        
        for (auto& word: wordList) {
            seen[word] = false;
        }
        
        if (!seen.count(endWord)) return 0;
        
        bfs.push(beginWord);
        seen[beginWord] = true;
        
        while (bfs.size() > 0) {
            int n = bfs.size();
            while(n-- > 0) {
                string curr = bfs.front(); bfs.pop();
                if (curr == endWord)
                    return n_transform;
                for (auto &c: curr) {
                    char tmp = c;
                    for (int i = 0; i < 26; ++i) {
                        c = i + 'a';
                        if (seen.count(curr) && !seen[curr]) {
                            bfs.push(curr);
                            seen[curr] = true;
                        }
                    }
                    c = tmp;
                }
            }
            ++n_transform;
        }        
        return 0;
    }
};