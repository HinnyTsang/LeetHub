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
    TreeNode* create_tree(vector<int>& nums, int l, int r) {
        
        int m = l + (r - l) / 2;
        if (l > r) return nullptr;
        
        TreeNode* curr = new TreeNode (nums[m]);
        
        curr->left = create_tree(nums, l, m - 1);
        curr->right = create_tree(nums, m + 1, r);
        
        return curr;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create_tree(nums, 0, nums.size() - 1);
    }
};