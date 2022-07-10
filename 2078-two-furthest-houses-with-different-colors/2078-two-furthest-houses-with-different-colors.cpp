class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), result = 0;
        
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors.back()) {
                result = max(result, n - 1 - i);
            }
            if (colors[i] != colors[0]){
                result = max(result, i);
            }
        }
        
        return result;
    }
};