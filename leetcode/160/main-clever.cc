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
        // You can see that:
        // len(A) == skipA + len(common_part)
        // len(B) == skipB + len(common_part)
        // Let's say we have two pointers a, b
        // let a walk skipA step
        // let b walk skipB step
        // Case 1: if skipA == skipB, then they will meet!
        // Case 2: if skipA != skipB:
        //         then we let a walk len(A) + skipB and len(B) + skipA
        //         we can find len(A) + skipB == len(B) + skipA
        //         and they will meet at the intersection!
        //         Because: a: skipA + len(common_part) + skipB
        //                  b: skipB + len(common_part) + skipA
        // Case 3: if there is no intersection:
        //         We let the end of the common part be nullptr
        //         we can find that a, b will meet at the nullptr in the end
        ListNode *a = headA;
        ListNode *b = headB;

        while(a != b){
            if(a != nullptr){
                a = a->next;
            }else{
                a = headB; // switch to the head of B
            }
            if(b != nullptr){
                b = b->next;
            }else{
                b = headA; // switch to the head of A
            }
        }
        return a;
    }
};
