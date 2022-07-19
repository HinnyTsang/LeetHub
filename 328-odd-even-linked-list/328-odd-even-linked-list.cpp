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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_root = new ListNode(0);
        ListNode *eve_root = new ListNode(0);
        ListNode *odd = odd_root, *eve = eve_root;
        bool is_odd = true;
        
        while (head) {
        
            if (is_odd) {
                odd->next = head;
                odd = odd->next;
            }
            else {
                eve->next = head;
                eve = eve->next;
            }
            is_odd = !is_odd;
            head = head->next;
        }
                
        odd->next = eve_root->next;
        eve->next = nullptr;
        
        return odd_root->next;
    }
};