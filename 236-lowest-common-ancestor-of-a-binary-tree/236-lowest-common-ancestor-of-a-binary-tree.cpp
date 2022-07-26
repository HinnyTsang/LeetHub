/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool is_ancestor(TreeNode* node, TreeNode* p) {
        
        if (!node) 
            return false;
        
        if (node->val == p->val) 
            return true;
        
        return is_ancestor(node->left, p) || is_ancestor(node->right, p);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (!root) return root;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if (l || r)
            return l? l: r;
        
        if (is_ancestor(root, p) && is_ancestor(root, q))
            return root;
        
        return nullptr;
    }
};