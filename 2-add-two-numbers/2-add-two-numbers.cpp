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
private:
    int carry = 0;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return carry? new ListNode(1): nullptr;
        }
        if (!l1) {
            swap(l1, l2);
        }
        
        if (!l2 && carry == 0) return l1;
        
        l1->val += carry;
        if (l2) l1->val += l2->val;
        
        carry = l1->val / 10;
        l1->val %= 10;
        
        l1->next = addTwoNumbers(l1->next, l2? l2->next: nullptr);
        
        return l1;
    }
};