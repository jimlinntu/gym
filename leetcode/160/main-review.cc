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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // l, mid, r
        // Initialize two pointers: p1, p2
        // When p1 move l + mid + r and p2 move r + mid + l
        // They will meet at the intersection!
        // Observe that if two lists have no intersection
        // Assume l, r are two lists' lengths

        // NOTE: nullptr will be a node too!

        ListNode *p1 = headA, *p2 = headB;
        while(p1 != p2){
            if(p1 == nullptr) p1 = headB;
            else p1 = p1->next;
            
            if(p2 == nullptr) p2 = headA;
            else p2 = p2->next;
        }

        return p1;
    }
};
