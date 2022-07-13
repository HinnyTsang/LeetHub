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
private:
    vector<vector<int>> result;
    
    void level_order_traversal(TreeNode* root, int level) {
        if (!root) 
            return;
        
        if (result.size() == level) 
            result.push_back({root->val});
        else
            result[level].push_back(root->val);
        
        level_order_traversal(root->left, level + 1);
        
        level_order_traversal(root->right, level + 1);
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        result = {};
        
        level_order_traversal(root, 0);
        
        return result;
    }
};