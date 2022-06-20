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
    const int MONITORED = 0;
    const int IS_CAMERA = 1;
    const int NOT_MONED = 2;
    
    int cameras;
    
    
    int dfs(TreeNode* p) {
        if (!p) return MONITORED;
        
        int left = dfs(p->left);
        int right = dfs(p->right);
        
        if (left == MONITORED && right == MONITORED) {
            return NOT_MONED;
        }
        else if (left == NOT_MONED || right == NOT_MONED) {
            ++cameras;
            return IS_CAMERA;
        }
        else {
            return MONITORED;
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        
        cameras = 0;
        int top = dfs(root);
        
        return cameras + (top == NOT_MONED? 1: 0);
    }
};