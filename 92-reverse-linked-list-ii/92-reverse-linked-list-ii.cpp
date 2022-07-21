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
    ListNode* reverse(ListNode* head, ListNode* end) {
        
        
        ListNode* work = head, *prev;
        
        while (work != end) {
            ListNode* curr = work->next;
            work->next = prev;
            prev = work;
            work = curr;
        }
        
        head->next = end;
        
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *root = new ListNode(0, head);
        ListNode *l = root, *r = root, *t, *c;
        
        while (left-- > 1) {
            l = l->next;
        }
        
        while (right-- > -1) {
            r = r->next;
        }
                
        l->next = reverse(l->next, r);

        return root->next;
    }
};