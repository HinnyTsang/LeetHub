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
    bool isValidBST(TreeNode* root, int small = 0, int large = 0, bool hasSmall = false, bool hasLarge = false) {
        if (!root) 
            return true;
        if ((hasSmall && root->val <= small) || (hasLarge && root->val >= large))
            return false;
        
        return isValidBST(root->left, small, root->val, hasSmall, true) && isValidBST(root->right, root->val, large, true, hasLarge);
    }
};