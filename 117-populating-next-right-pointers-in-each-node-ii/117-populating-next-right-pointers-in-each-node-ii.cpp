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
        
        if (!root) return root;
        
        Node* next_head = nullptr;
        Node* next_work = nullptr;
        Node* curr = root;
        
        while (curr != nullptr) {
            if (curr->left) {
                if (!next_head) {
                    next_head = next_work = curr->left;
                }
                else {
                    next_work->next = curr->left;
                    next_work = curr->left;
                }
            }
            if (curr->right) {
                if (!next_head) {
                    next_head = next_work = curr->right;
                }
                else {
                    next_work->next = curr->right;
                    next_work = curr->right;
                }
            }
            curr = curr->next;
        }
        
        connect(next_head);
            
        return root;
    }
};