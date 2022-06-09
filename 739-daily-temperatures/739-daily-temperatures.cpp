class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> prev_days;
        vector<int> result(temperatures.size(), 0);
        
        for (int i = 0; i < temperatures.size(); ++i) {
            while (prev_days.size() > 0 && temperatures[prev_days.top()] < temperatures[i]) {
                auto day = prev_days.top(); prev_days.pop();
                result[day] = i - day;
            }
            prev_days.push(i);
        }
        return result;
    }
};