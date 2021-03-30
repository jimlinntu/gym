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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Idea: store the n-th node in front the current node
        ListNode *target_prev = nullptr;
        ListNode *target = nullptr;
        ListNode *cur = head;
        // At least we can traverse n nodes
        // NOTE: we already step 1 node when we are on the head
        for(int i = 1; i < n; i++){
            assert(cur->next != nullptr);
            cur = cur->next;
        }
        // Now head is n-th in front of cur (including cur)
        target = head;
        // walk until we reach the last node
        for(;cur->next != nullptr;){
            target_prev = target;
            target = target->next;
            assert(target != nullptr);
            cur = cur->next;
            // If cur is at the end of this list
            // target will be the n-th node from the end!
        }

        if(target_prev != nullptr){
            //     target_prev -> target -> target->next
            // ==> target_prev -> target->next
            target_prev->next = target->next;
        }else{
            // (Optional) remove head
            // head is moved
            head = target->next;
        }
        return head;
    }
};
