/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // O(log(n)) space
        // O(n) time.
        queue<Node*> nodes;
        
        if (root) nodes.push(root);
        
        while (!nodes.empty()) {
            
            int n = nodes.size();
            
            for (int i = 0; i < n; ++i) {   
                Node* curr = nodes.front(); nodes.pop();
                
                curr->next = i < n - 1? nodes.front() : nullptr;
                
                if (curr->left) nodes.push(curr->left);
                if (curr->right) nodes.push(curr->right);
            }
        }
        
            
        return root;
    }
};