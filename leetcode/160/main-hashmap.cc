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
    unordered_map<ListNode*, bool> exist;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for(ListNode *a=headA; a != nullptr; a=a->next){
            exist[a] = true;
        }
        for(ListNode *b=headB; b != nullptr; b=b->next){
            if(exist[b]) return b;
        }
        return nullptr;
    }
};
