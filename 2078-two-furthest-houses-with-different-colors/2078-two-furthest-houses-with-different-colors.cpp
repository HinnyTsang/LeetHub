class Solution {
public:
    int maxDistance(vector<int>& colors) {
        unordered_map<int, int> prev_color;
        int result = 0;
        
        for (int i = 0; i < colors.size(); ++i) {
            if (!prev_color.count(colors[i])) {
                prev_color[colors[i]] = i;
            }

            for (auto& [color, location]: prev_color) {
                if (color != colors[i])
                    result = max(result, i - location);
            }
        }
        
        return result;
    }
};