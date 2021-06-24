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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode *head = &dummy;
        ListNode *cur = head;
        while(l1 != nullptr and l2 != nullptr){
            if(l1->val <= l2->val){
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        assert(l1 == nullptr or l2 == nullptr);
        if(l1) cur->next = l1;
        else if(l2) cur->next = l2;
        return head->next;
    }
};
