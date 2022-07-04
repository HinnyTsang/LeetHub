class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int increase = 0, decrease = 0, peak = 0, sum = 1;
        
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                peak = ++increase;
                decrease = 0;
                sum += 1 + increase;
            }
            else if (ratings[i] < ratings[i - 1]) {
                increase = 0;
                decrease++;
                sum += decrease + (peak >= decrease? 0: 1) ;
            }
            else {
                ++sum;
                increase = decrease = peak = 0;
            }
        }
        
        return sum;
    }
};