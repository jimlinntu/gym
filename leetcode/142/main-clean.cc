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
        // See my explanation pdf
        ListNode dummy;
        dummy.next = head;

        ListNode *tortise = &dummy;
        ListNode *hare = &dummy;
        bool has_cycle = false;        
        while(tortise != nullptr and hare != nullptr){
            tortise = tortise->next;

            if(hare->next != nullptr) hare = hare->next->next;
            else hare = nullptr;

            if(tortise == hare and tortise != nullptr){
                has_cycle = true;
                break;
            }
        }
        if(!has_cycle) return nullptr;
        hare = &dummy;
        while(hare != tortise){
            hare = hare->next;
            tortise = tortise->next;
        }
        return hare;
    }
};
