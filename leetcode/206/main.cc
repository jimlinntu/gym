/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool is_iteratively=false;

ListNode *recursively_reverse(ListNode *head, ListNode *prev){
    if(head == NULL){
        return prev; // the reversed head
    }
    ListNode *next = head->next;
    head->next = prev;
    prev = head;
    return recursively_reverse(next, prev); // return head
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(is_iteratively){
            ListNode *next;
            ListNode *prev=NULL;
            for(ListNode *iter=head; iter!=NULL; iter=next){
                next = iter->next;
                iter->next = prev;
                prev = iter;
            }
            return prev;
        }else{
            return recursively_reverse(head, NULL);
        }
    }
};
