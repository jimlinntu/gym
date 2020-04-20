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
    int n = 0;
    // Compute n
    for(iter=head; iter != NULL; iter = iter->next, n++){}
    if(n == 0) return true;
    
    // Set n to the first half boundary
    int boundary = (n % 2 == 0)?(n / 2):((n+1)/2);
    
    ListNode *prev = NULL; // set previous to NULL
    ListNode *next;
    iter = head;
    // Let the first half be reversed linked list
    for(int i = 0; i < boundary; i++, iter=next){
        next = iter->next; // save the next one
        iter->next = prev; // point to the previous one
        prev = iter; // save previous one
    }
    // Compare
    for(ListNode *l_head=(n % 2 == 0)?(prev):(prev->next), *r_head=iter; l_head != NULL; 
        l_head=l_head->next, r_head=r_head->next){
        if(l_head->val != r_head->val){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return check(head);
    }
};
