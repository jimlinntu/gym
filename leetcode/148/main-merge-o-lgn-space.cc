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
    ListNode* merge_sort(ListNode *head, int n){
        if(n == 0) return nullptr;
        if(n == 1){
            head->next = nullptr;
            return head;
        }
        // Split it into two parts: [0, n/2) and [n/2, n)
        ListNode *right_head = head;
        int m = n / 2;
        while((m--) > 0) right_head = right_head->next;
        ListNode *left = merge_sort(head, n / 2);
        ListNode *right = merge_sort(right_head, n - n/2);

        // Merging algorithm: O(n)
        ListNode *fake_head = new ListNode();
        ListNode *cur = fake_head;
        while(left != nullptr or right != nullptr){
            if(left != nullptr and right != nullptr){
                if(left->val <= right->val){
                    cur->next = left;
                    left = left->next;
                }else{
                    cur->next = right;
                    right = right->next;
                }
            }else if(left != nullptr){
                cur->next = left;
                left = left->next;
            }else{
                cur->next = right;
                right = right->next;
            }
            assert(cur != nullptr);
            cur = cur->next;
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

