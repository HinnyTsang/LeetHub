class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        priority_queue<int> taked_course;
        
        sort(courses.begin(), courses.end(), [](auto& a, auto&b) { return a[1] < b[1];});
        
        int totalTime = 0;
        
        for (auto& course: courses) {
            
            if (course[0] > course[1])
                continue;
            
            if (totalTime + course[0] <= course[1]) {
                taked_course.push(course[0]);
                totalTime += course[0];
            }
            else if (taked_course.top() > course[0]) {
                totalTime += course[0] - taked_course.top();
                taked_course.pop();
                taked_course.push(course[0]);
            }
        }
        
        
        return taked_course.size();
    }
};