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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root = new ListNode(0, head);
        ListNode* work = root, *temp;
        
        while (n-- > 0 && work) {
            work = work->next;
        }
        
        temp = root;
        
        while (work->next) {
            temp = temp->next;
            work = work->next;
        }
        
        
        if (temp && temp->next)
            temp->next = temp->next->next;
        
        return root->next;
    }
};