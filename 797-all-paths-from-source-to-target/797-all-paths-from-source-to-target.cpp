class Solution {
private:
    void back_tracking(vector<vector<int>>& graph, vector<int>& work, vector<vector<int>>& res) {
        
        if (work.back() == graph.size() - 1) {
            res.push_back(work);
            return;
        }
        
        int curr = work.back();
        
        for (int i: graph[curr]) {
            work.push_back(i);
            back_tracking(graph, work, res);
            work.pop_back();
        }
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> res;
        vector<int> work(1, 0);
        
        back_tracking(graph, work, res);
        
        return res;
    }
};