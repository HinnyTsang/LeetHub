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
    int result;
    int dfs (TreeNode* root) {
        
        if (!root) return 0;
        
        int l = 0, r = 0;
        
        if (root->left) l = 1 + dfs(root->left);
        
        if (root->right) r = 1 + dfs(root->right);
        
        result = max(result, l + r);
        
        return max(l, r);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        result = 0;
        
        return max(result, dfs(root));
    }
};