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
class BSTIterator {
private:
    stack<TreeNode*> prev;
public:
    
    void push_left(TreeNode* node) {
        if (!node) return;
        prev.push(node);
        if (node->left) {
            push_left(node->left);
            node->left = nullptr;
        }
    }
    
    BSTIterator(TreeNode* root) {
        push_left(root);
    }
    
    int next() {
        TreeNode* curr = prev.top();
        prev.pop();
        push_left(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !prev.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */