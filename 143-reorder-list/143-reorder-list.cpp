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
    void reorderList(ListNode* head) {
        
        if (!head || !head->next) return;
        
        vector<ListNode*> storage;
        
        ListNode* work = head;
        
        for (int i = 0; work; work = work->next, ++i) {
            storage.push_back(work);
        }
        
        int l = 0, r = storage.size() - 1;
        
        while (r >= l) {
            storage[l]->next = storage[r];
            storage[r]->next = storage[l + 1];
            ++l, --r;
        }
        
        storage[max(r+1, 0)]->next = nullptr;
        
    }

};