class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        
        unordered_set<int> seen;
        int result = 1;
        
        for (int n: rolls) {
            seen.insert(n);
            
            if (seen.size() == k) {
                ++result;
                seen.clear();
            }
            
        }
        return result;
    }
};