/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* lt_root = new ListNode();
        ListNode* geq_root = new ListNode();
        ListNode* lt = lt_root, *geq = geq_root;
        ListNode* work = head;
        
        while (work != nullptr) {
            
            cout << work->val; 
            if (work->val < x) {
                lt->next = work;
                lt = work;
            }
            else {
                geq->next = work;
                geq = work;
            }
            work = work->next;
        }
                
        lt->next = geq_root->next;
        geq->next = nullptr;
        
        return lt_root->next;
    }
};