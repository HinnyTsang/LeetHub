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
    int n;
    int get_num(string& s, int& i) {
        int num = 0;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + s[i] - '0'; 
            ++i;
        }
        return num;
    }
public:
    TreeNode* recoverFromPreorder(string s) {
        
        stack<TreeNode*> nodes;
        n = s.size();
        
        for (int i = 0; i < n;) {
            int dashed = 0;
            
            
            
            while (i < n && s[i] == '-') {
                ++dashed, ++i;
            }
            
            int num = get_num(s, i);
            
            TreeNode* curr = new TreeNode(num);
            
            if (dashed == 0) {
                nodes.push(curr);
            }
            else {
            
                while (nodes.size() > dashed) 
                    nodes.pop();
            
                TreeNode* top = nodes.top();
                
                if (!top->left) {
                    top->left = curr;
                }
                else {
                    top->right = curr;
                }
                nodes.push(curr);

            }
        }
        
        while (nodes.size() > 1) nodes.pop();
        
        return nodes.top();
    }
};