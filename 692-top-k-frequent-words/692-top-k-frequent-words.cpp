class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> word_count;
        vector<string> result;
        
        for (auto& word: words) {
            ++word_count[word];
        }
        for (auto& [word, count]: word_count ) {
            result.push_back(word);
        }
        
        partial_sort(result.begin(), result.begin() + k, result.end(), [&](auto& a, auto& b) {
            if (word_count[a] == word_count[b])
                return a < b;
            else 
                return word_count[a] > word_count[b];
        });
        
        return vector<string>(result.begin(), result.begin() + k);
    }
};