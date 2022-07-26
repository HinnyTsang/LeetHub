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
    int result, K;
    int find_k(TreeNode* root, int parent) {
        
        
        
        int curr, next;
        
        if (result != -1)
            return 0;
        
        if (!root->left) {
            curr = parent + 1;
        }
        else {
            curr = find_k(root->left, parent) + 1;
        }
        
        if (result != -1) return 0;
        
        if (curr == K) {
            result = root->val;
            return 0;
        }
        
        if (!root->right) {
            return curr;
        }
        else {
            return find_k(root->right, curr);    
        } 
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        result = -1;
        K = k;
        
        find_k(root, 0);
        
        return result;
    }
};