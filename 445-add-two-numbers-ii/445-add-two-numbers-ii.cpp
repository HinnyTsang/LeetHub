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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<ListNode*> s1, s2;
        ListNode* result = nullptr;
        int carry = 0;
        
        while (l1) {
            s1.push(l1);
            l1 = l1->next;
        }
        
        while (l2) {
            s2.push(l2);
            l2 = l2->next;
        }
        
        while (!s1.empty() || !s2.empty()) {
            int val = carry;
            
            if (!s1.empty()) {
                val += s1.top()->val;
                s1.pop();
            }
            if (!s2.empty()) {
                val += s2.top()->val;
                s2.pop();
            }
            
            carry = val / 10;
            val %= 10;
            
            result = new ListNode(val, result);
        }
        
        
        
        return carry? new ListNode(1, result): result;
    }
};