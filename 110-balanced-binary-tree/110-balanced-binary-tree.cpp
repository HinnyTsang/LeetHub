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
    int recursion(TreeNode* root) {
        if (!root || !result) {
            return 0;
        }
        int l = recursion(root->left);
        int r = recursion(root->right);
        
        if (abs(r - l) > 1) {
            result = false;
        }
        return max(l, r) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        result = true;
        recursion(root);
        return result;
    }
};