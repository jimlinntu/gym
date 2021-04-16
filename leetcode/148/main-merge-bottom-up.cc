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
    int getLength(ListNode *l){
        int n = 0;
        while(l != nullptr){
            n++;
            l = l->next;
        }
        return n;
    }
    ListNode *merge(ListNode *left, int left_n,
                    ListNode *right, int right_n){
        if(left_n == 0) return right;
        if(right_n == 0) return left;
        ListNode *fake_head = new ListNode();
        ListNode *cur = fake_head;
        ListNode *right_end_next;
        // left_n, right_n indicate the remaining nodes in left and right
        while(left_n > 0 or right_n > 0){
            // left --->  ... ---> right ----> ... ----> right_end_next
            // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ <--- this region is sorted!
            if(right_n == 1) right_end_next = right->next;
            if(left_n > 0 and right_n > 0){
                if(left->val <= right->val){
                    cur->next = left;
                    left = left->next;
                    left_n--;
                }else{
                    cur->next = right;
                    right = right->next;
                    right_n--;
                }
            }else if(left_n > 0){
                cur->next = left;
                left = left->next;
                left_n--;
            }else{
                cur->next = right;
                right = right->next;
                right_n--;
            }
            cur = cur->next;
        }
        // Remember to concatenate nodes after right_end_next (including)
        cur->next = right_end_next;
        ListNode *real_head = fake_head->next;
        delete fake_head;
        return real_head;
    }
    ListNode *move(ListNode *node, int n){
        while((n--) > 0) node = node->next;
        return node;
    }
    ListNode* merge_sort(ListNode *head, int n){
        // O(log n) steps
        ListNode *fake_head = new ListNode();
        fake_head->next = head;

        for(int len = 1; len < n; len *= 2){
            ListNode *left = fake_head->next;
            ListNode *prev_end = fake_head;
            for(int i = 0; i < n; i += 2*len){
                // [i, i+len) and [i+len, i+2*len) can be merged
                // Ex. len = 2, [1, 2, 3, 4, 5]
                //                           ^ <---- left
                int left_n = min(n, i+len) - i;
                int right_n = min(n, i+2*len) - (i+left_n);
                assert(left_n != 0); // left_n will be an nonzero

                ListNode *right = move(left, left_n);

                if(right_n == 0) assert(right == nullptr);
                // NOTE: after merged, left and right will in different positions
                // So we shouldn't use left, right after this function anymore
                ListNode *merged = merge(left, left_n, right, right_n);
                // Make sure:
                // ---> prev_end ---> |[i, i+len) ---> [i+len, i+2*len)|
                //                    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ sorted region
                prev_end->next = merged;
                // fast forward (left_n + right_n) steps
                prev_end = move(prev_end, left_n + right_n);
                left = move(merged, left_n + right_n);
            }
        }
        ListNode *real_head = fake_head->next;
        delete fake_head;
        return real_head;
    }
    ListNode* sortList(ListNode* head) {
        int n = getLength(head);
        return merge_sort(head, n);
    }
};
