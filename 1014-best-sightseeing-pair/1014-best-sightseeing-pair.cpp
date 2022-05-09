class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int prev = 0;
        int score = values[0];
        int max_score = 0;
        
        
        for(int i = 1; i < values.size(); ++i) {
            --score;
            max_score = max(score + values[i], max_score);
            if (values[i] > score) {
                score = values[i];
                prev = i;
            }
        }
        
        return max_score;
    }
};