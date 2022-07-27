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
    void flatten(TreeNode* root) {
        
        if (!root || (!root->left && !root->right))
            return;
        
        
        TreeNode* l = root->left; root->left = nullptr;
        TreeNode* r = root->right, *w;
        
        flatten(l);
        flatten(r);
        
        
        if (l) {
            root->right = l;
            for (w = l; w && w->right; w = w->right);
        }
        else w = root;
        
        w->right = r;         
    }
};