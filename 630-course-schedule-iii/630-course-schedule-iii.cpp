class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        static auto compare = [](auto& a, auto& b) {
            return a.first < b.first;        
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> taked_course(compare);
        
        sort(courses.begin(), courses.end(), [](auto& a, auto&b) {
            return a[1] < b[1];    
        });
        
        int totalTime = 0;
        
        for (auto& course: courses) {
            
            if (course[0] > course[1])
                continue;
            
            if (totalTime + course[0] <= course[1]) {
                taked_course.emplace(course[0], course[1]);
                totalTime += course[0];
            }
            else if (taked_course.top().first > course[0]) {
                totalTime += course[0] - taked_course.top().first;
                taked_course.pop();
                taked_course.emplace(course[0], course[1]);
            }
        }
        
        
        return taked_course.size();
    }
};