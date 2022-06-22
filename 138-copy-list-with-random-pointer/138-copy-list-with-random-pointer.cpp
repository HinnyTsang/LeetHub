/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, int> node_index;
        vector<Node*> index_node;
            
        Node* w = head;
        
        for (int i = 0; w; ++i, w = w->next) {
            node_index[w] = i;
            index_node.push_back(new Node(w->val));
        }

        index_node.push_back(nullptr);
        
        w = head;
        for (int i = 0; w; ++i, w = w->next) {
            index_node[i]->next = index_node[i+1];
            index_node[i]->random = w->random? index_node[node_index[w->random]]: nullptr;
        }
         
        
        return index_node[0];
    }
};