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
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        int carry = 0;
        ListNode dummy;
        ListNode *prev = &dummy;
        while(cur1 or cur2){
            int val = carry;
            if(cur1) val += cur1->val;
            if(cur2) val += cur2->val;

            carry = val / 10;
            val = val%10;
            ListNode *node = new ListNode(val);
            prev->next = node;            
            prev = node;
            
            if(cur1) cur1 = cur1->next;
            if(cur2) cur2 = cur2->next;
        }
        // remember the potential carry digit
        if(carry){
            ListNode *node = new ListNode(carry);
            prev->next = node;
            prev = node;
        }
        return dummy.next;
    }
};
