class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int coins [] = {0, 0, 0};
        
        for (int& bill: bills) {
            if (bill == 5) {
                ++coins[0];
            }
            else if (bill == 10) {
                if (coins[0] == 0) return false;
                --coins[0];
                ++coins[1];
            }
            else if (bill == 20) {
                if (coins[0] == 0) return false;
                if (coins[1] > 0) {
                    --coins[1];
                    --coins[0];
                }
                else {
                    if (coins[0] < 3) return false;
                    coins[0] -= 3;
                }
            }
        }
        
        return true;
    }
};