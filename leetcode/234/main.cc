/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool check(ListNode *head){
    ListNode *iter;
    ListNode *prev;
    ListNode *next;
    int n = 0;
    // Compute n
    for(iter=head; iter != NULL; iter = iter->next, n++){
    }
    if(n == 0) return true;
    
    if(n % 2 == 0){
        iter = head;
        n /= 2;
        // Let the first half be reversed linked list
        for(int i = 0; i < n; i++, iter=next){
            next = iter->next; // save the next one
            if(i != 0) iter->next = prev; // point to the previous one
            else iter->next = NULL;
            prev = iter; // save previous one
        }
        // Compare
        for(ListNode *l_head=prev, *r_head=iter; l_head != NULL; 
            l_head=l_head->next, r_head=r_head->next){
            if(l_head->val != r_head->val){
                return false;
            }
        }
        return true;
    }else{
        iter = head;
        n = (n+1)/2;
        // Let the first half be reversed linked list
        for(int i = 0; i < n; i++, iter=next){
            next = iter->next; // save the next one
            if(i != 0) iter->next = prev; // point to the previous one
            else iter->next = NULL;
            prev = iter; // save previous one
        }
        // Compare
        for(ListNode *l_head=prev->next, *r_head=iter; l_head != NULL; 
            l_head=l_head->next, r_head=r_head->next){
            if(l_head->val != r_head->val){
                return false;
            }
        }
        return true;
    }
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return check(head);
    }
};
