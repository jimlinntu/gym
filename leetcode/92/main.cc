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
        if(m == n) return head; // no need to do any operations on it
        int idx = 1;
        ListNode *next;
        // linkedlist = [left; mid (m~n); right]
        ListNode *left_end=NULL, *mid_start=NULL;
        for(ListNode *iter=head, *prev=NULL; iter!=NULL; idx++){
            if(m == idx){
                left_end = prev;
                mid_start = iter;
            }else if(idx == n){
                if(left_end != NULL){
                    left_end->next = iter;
                }else{
                    // update new head
                    head = iter;
                }
                mid_start->next = iter->next;
            }
            
            // reverse the linked list in [m, n]
            if(m <= idx && idx <= n){
                next = iter->next;
                iter->next = prev; // point to the previous one
                prev = iter; // save previous one
                iter = next;
            }else{
                prev = iter; // save previous one
                iter= iter->next; // move to the next one
            }
        }
        
        return head;
    }
};
