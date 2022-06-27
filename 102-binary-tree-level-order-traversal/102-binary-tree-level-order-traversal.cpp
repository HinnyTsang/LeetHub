/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> bfs;
        vector<vector<int>> res;
        if (root) bfs.push(root);
        
        while (!bfs.empty()) {
            int n = bfs.size();
            res.push_back(vector<int>(n,0));
            
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = bfs.front(); bfs.pop();
                
                res.back()[i] = curr->val;
                
                if (curr->left) bfs.push(curr->left);
                if (curr->right) bfs.push(curr->right);               
            }
            
        }
        
        return res;
    }
};