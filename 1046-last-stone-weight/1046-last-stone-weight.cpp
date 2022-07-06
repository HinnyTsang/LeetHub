class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stone(stones.begin(), stones.end());
        
        while (stone.size() > 1) {
            int a = stone.top(); stone.pop();
            int b = stone.top(); stone.pop();
            
            if (a != b)
                stone.push(a - b);
        }
        
        return stone.empty()? 0: stone.top();
    }
};