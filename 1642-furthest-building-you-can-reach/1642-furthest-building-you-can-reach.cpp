class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> useLadders;
    
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int result = 0;
        for (int i = 1; i < heights.size(); ++i) {
            int diff = heights[i] - heights[i - 1];
            
            if (diff <= 0) {
                continue;
            }
            
            useLadders.push(diff);
            
            if (useLadders.size() > ladders) {
                
                int useBrick = useLadders.top(); useLadders.pop();
                
                bricks -= useBrick;
                
                if (bricks < 0) {
                    return i - 1;
                }
            }
            
            
        }
        
        return heights.size() - 1;
    }
};