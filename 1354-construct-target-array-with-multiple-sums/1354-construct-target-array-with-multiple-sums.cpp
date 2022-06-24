class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> seen(target.begin(), target.end());
        long long curr_sum = accumulate(target.begin(), target.end(), 0LL);
        
        // partial sum + prev = top;
        // partial sum + top = curr sum;
        
        while (curr_sum > 1 && seen.top() > curr_sum/2) {
            
            int curr_max = seen.top(); seen.pop();
            
            curr_sum -= curr_max;
            
            // sum - max + max = sum
            // prev_sum - prev_max + curr_max = curr_sum
            // [9,3,5] curr_sum = 9 + 3 + 5 = 17, curr_max = 9
            // x + 3 + 5 = x + partial_sum,     partial_sum + curr_max = curr_sum;
            // x + partial_sum = curr_max
            // x = curr_max - partial_sum
            
            
            if (curr_sum < 1) return false;
            
            if (curr_sum == 1) return true;
                        
            auto x = curr_max % curr_sum;
            
            seen.push(x);
            
            curr_sum += x;
        }

        return curr_sum == seen.size();
    }
};