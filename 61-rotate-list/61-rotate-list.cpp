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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (k == 0) return head;
        
        int n = 0;
        
        ListNode* w = head;
        
        while (w) {
            ++n;
            w = w->next;
        }
        
        if (n == 0 || k == n) return head;
        
        k %= n;
        
        if (k == 0) return head;
        
        w = head;
        ListNode* p;
        
        for (int i = 0; i < (n - k); ++i) {
            p = w;
            w = w->next;
        }
        
        p->next = nullptr;
        ListNode* res = w;
        
        while (w->next) {
            w = w->next;
        }
        
        w -> next = head;
            
        
        return res;
    }
};