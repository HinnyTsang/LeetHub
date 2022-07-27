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
    void recursion(vector<int>& result, TreeNode* p, int level) {
        if (!p)
            return;
        if (result.size() < level)
            result.push_back(p->val);
        
        recursion(result, p->right, level + 1);
        recursion(result, p->left, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        recursion(result, root, 1);
        
        return result;
    }
};