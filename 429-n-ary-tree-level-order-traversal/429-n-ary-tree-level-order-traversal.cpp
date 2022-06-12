/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        queue<Node*> prev;
        if(root) prev.push(root);
        
        while (prev.size()) {
            int n = prev.size();
            
            vector<int> curr;
            
            for (int i = 0; i < n; ++i) {
                auto a = prev.front(); prev.pop();
                curr.push_back(a->val);
                
                for (auto& child: a->children) {
                    prev.push(child);
                }
            }
            res.push_back(curr);
        }
        
        return res;
    }
};