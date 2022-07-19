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
    
    bool result;
    
    int helper(TreeNode* root) {
        if (!root || !result) return 0;
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        if (abs(l - r) > 1) {
            result = false;
            return -1;
        }
        
        return max(l, r) + 1;
    }
public:
    
    bool isBalanced(TreeNode* root) {
        
        result = true;
        
        helper(root);
        
        return result;
    }
};