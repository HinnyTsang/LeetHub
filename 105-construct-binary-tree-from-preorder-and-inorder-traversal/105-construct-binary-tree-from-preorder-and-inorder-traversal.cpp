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
    TreeNode* helper (vector<int>& preorder, vector<int>& inorder, int& preorder_idx, int l, int r) {
        if (preorder_idx == inorder.size() || l > r) {
            return nullptr;
        }
        
        int inorder_idx = l;
        while (inorder[inorder_idx] != preorder[preorder_idx])
            ++inorder_idx;
        
        TreeNode* root = new TreeNode(preorder[preorder_idx]);
        
        ++preorder_idx;
        
        root->left = helper (preorder, inorder, preorder_idx, l, inorder_idx-1);
        
        root->right = helper (preorder, inorder, preorder_idx, inorder_idx+1, r);
        
        return root;
    } 
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorder_idx = 0;
        return helper (preorder, inorder, preorder_idx, 0, preorder.size() - 1);
    }
    
};