/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy_head = ListNode(0);
        dummy_head.next = head;
        ListNode *left_end = &dummy_head;
        for(int i = 1; i < m; i++, left_end=left_end->next){}
        ListNode *anchor = left_end->next;
        // let node after this anchor follow left_end
        // Note: there are (m-n) nodes after m-th node need to be moved
        for(int i = m; i < n; i++){
            // Note: anchor->next != NULL
            // because there must be (m-n) nodes after this anchor
            ListNode *anchor_next_next = (anchor->next)->next; 
            (anchor->next)->next = left_end->next; //
            left_end->next = anchor->next; // point to anchor's child
            anchor->next = anchor_next_next; // point to anchor child's next
        }
        return dummy_head.next;
    }
};
