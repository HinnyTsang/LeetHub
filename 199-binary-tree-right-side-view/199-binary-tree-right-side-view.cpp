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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        deque<TreeNode*> bfs;
        
        if (root) bfs.push_back(root);
        
        while (!bfs.empty()) {
            
            result.push_back(bfs.back()->val);
            
            int n = bfs.size();
            
            while (n-- > 0) {
                TreeNode* curr = bfs.front();
                bfs.pop_front();
                
                if (curr->left) 
                    bfs.push_back(curr->left);
                if (curr->right) 
                    bfs.push_back(curr->right);
                
            }
        }
        
        return result;
    }
};