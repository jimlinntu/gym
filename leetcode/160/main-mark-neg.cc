class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ans = nullptr;
        // tag values starting from headA negatives
        for(ListNode *a=headA; a != nullptr; a = a->next){
            a->val = -a->val;
        }
        for(ListNode *b=headB; b != nullptr; b = b->next){
            if(b->val < 0){
                ans = b;
                break;
            }
        }
        // restore them
        for(ListNode *a=headA; a != nullptr; a = a->next){
            a->val = -a->val;
        }
        return ans;
    }
};
