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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(INT_MIN, head);
        ListNode *h = &dummy;

        ListNode *cur = h; // cur == the last unique ListNode*
        for(; cur != nullptr;){
            // determine whether to delete
            if(cur->next != nullptr and cur->next->next != nullptr and
               cur->next->val == cur->next->next->val){
                int delete_val = cur->next->val;
                ListNode *p = cur->next;
                while(p != nullptr and p->val == delete_val){
                    // remove p one by one and move on
                    ListNode *n = p->next;
                    p->next = nullptr;
                    cur->next = n;
                    delete p;
                    p = n;
                }
            }else cur = cur->next; // otherwise just go next
        }
        return h->next;
    }
};
