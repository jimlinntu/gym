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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *prev = nullptr;
        ListNode *curr = nullptr;
        int val;
        int carry = 0;
        // we continue if there exists at least one not nullptr
        while(l1 != nullptr or l2 != nullptr){
            val = 0;
            if(l1 != nullptr){
                val += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                val += l2->val;
                l2 = l2->next;
            }
            val += carry; // add carry bit from lower digits
            // compute the carry bit for later
            carry = val / 10;
            val = val % 10;
            curr = new ListNode(val);
            if(head == nullptr) head = curr;
            if(prev != nullptr) prev->next = curr;
            prev = curr;
        }
        // Edge case
        if(carry == 1){
            curr = new ListNode(carry);
            assert(prev != nullptr);
            prev->next = curr;
            prev = curr;
        }
        return head;
    }
};
