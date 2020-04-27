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
    ListNode *detectCycle(ListNode *head) {
        // Floyd algorithm
        ListNode *tortoise = head;
        ListNode *hare = head;
        
        while(true){
            // There is no loop
            if(tortoise == NULL || hare == NULL || hare->next == NULL){
                return NULL;
            }
            tortoise = tortoise->next;
            hare = hare->next->next;
            // If it contains loop, tortoise and hare will meet
            if(tortoise == hare){
                break;
            }
        }
        ListNode *start_of_the_loop = head;
        while(true){
            if(start_of_the_loop == tortoise){
                break;
            }
            start_of_the_loop = start_of_the_loop->next;
            tortoise = tortoise->next;
        }
        return start_of_the_loop;
    }
};
