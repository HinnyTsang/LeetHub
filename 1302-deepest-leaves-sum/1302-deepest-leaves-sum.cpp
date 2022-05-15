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
    int deepestLeavesSum(TreeNode* root) {
        
        queue<TreeNode*> bfs;
        
        if (root) bfs.push(root);
        
        int res = 0;
        
        while (bfs.size()) {
            int n = bfs.size();
            res = 0;
            
            while (n--) {
                auto curr = bfs.front(); bfs.pop();
                
                res += curr->val;
                
                if (curr->left) bfs.push(curr->left);
                if (curr->right) bfs.push(curr->right);
            }
        }
        
        return res;
    }
};