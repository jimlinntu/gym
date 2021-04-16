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
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode *head = new ListNode();
        ListNode *cur = head;
        ListNode *cur1 = l1, *cur2 = l2;
        while(cur1 != nullptr or cur2 != nullptr){
            if(cur1 != nullptr and cur2 != nullptr){
                if(cur1->val < cur2->val){
                    cur->next = cur1;
                    cur1 = cur1->next;
                }else{
                    cur->next = cur2;
                    cur2 = cur2->next;
                }
            }else if(cur1 != nullptr){
                cur->next = cur1;
                cur1 = cur1->next;
            }else{
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        ListNode *real_head = head->next;
        delete head;
        return real_head;
    }
};
