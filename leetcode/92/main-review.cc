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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy;
        ListNode *dhead = &dummy;
        dhead->next = head;
        // 0-index
        left--;
        right--;
        ListNode *prev = dhead;
        // Move l, r to the correct places
        ListNode *l = head;
        ListNode *r = head;
        for(; left > 0; l = l->next, r = r->next, left--, right--){
            prev = l;
        }
        for(; right > 0; r = r->next, right--){
        }
        // Reverse [l, r]
        prev->next = r; // points to r

        ListNode *end = r->next;
        ListNode *p = end;
        ListNode *next;
        for(ListNode *cur = l; cur != end; cur = next){
            next = cur->next;
            cur->next = p;
            p = cur;
        }
        return dhead->next;
    }
};
