class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        static auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) > prev_days(cmp);
        vector<int> result(temperatures.size(), 0);
        
        for (int i = 0; i < temperatures.size(); ++i) {
            while (prev_days.size() > 0 && prev_days.top().first < temperatures[i]) {
                auto [temp, day] = prev_days.top(); prev_days.pop();
                result[day] = i - day;
            }
            prev_days.emplace(temperatures[i], i);
        }
        return result;
    }
};