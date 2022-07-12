class Solution {

private:
    bool done;
    void back_track(int i, vector<int>& sticks, const int& edge_length, int lengths []) {
        if (i == sticks.size())
            done = true;
        
        if (done) return;
        
        for (int j = 0; j < 4; ++j) {
            if (lengths[j] + sticks[i] <= edge_length) {
                lengths[j] += sticks[i];
                back_track(i+1, sticks, edge_length, lengths);
                lengths[j] -= sticks[i];
            }
        }
    }
public:
    
    bool makesquare(vector<int>& matchsticks) {
        
        int total_length = accumulate(matchsticks.begin(), matchsticks.end(), 0); 
        int edge_length = total_length / 4; 
        int lengths [] = {0, 0, 0, 0};
        done = false;
        
        if (
            total_length % 4 != 0 ||
            *max_element(matchsticks.begin(), matchsticks.end()) > edge_length
        )
            return false;
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        back_track(0, matchsticks, edge_length, lengths);

        return done;
    }
};