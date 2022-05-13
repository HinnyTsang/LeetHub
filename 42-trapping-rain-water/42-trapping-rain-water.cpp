class Solution {
public:
    int trap(vector<int>& height) {
        
        stack<pair<int, int>> prev;
        int volume = 0;
        
        
        
        for (int i = 0; i < height.size(); ++i) {
            
            int bot = 0;
            
            while (!prev.empty() && prev.top().first <= height[i]) {
                
                volume += (i - prev.top().second - 1) * (prev.top().first - bot);
                
                bot = max(bot, prev.top().first); prev.pop();
            }    
            
            if (!prev.empty()) {
                volume += (i - prev.top().second - 1) * (height[i] - bot);
            }
            
            prev.emplace(height[i], i);
        }
        
        return volume;
    }
};