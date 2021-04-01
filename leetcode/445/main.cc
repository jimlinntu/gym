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
    int length_of_list(ListNode *l){
        int n = 0;
        while(l != nullptr){
            n++;
            l = l->next;
        }
        return n;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int m = length_of_list(l1);
        int n = length_of_list(l2);
        // 99 + 99 == 198
        int out_size = max(m, n)+1;
        vector<int> ans(out_size, 0);
        ListNode *cur_l1 = l1;
        ListNode *cur_l2 = l2;
        // Accumulate each digit
        for(int i = 1; i < out_size; i++){
            if(out_size - i <= m){
                ans[i] += cur_l1->val;
                cur_l1 = cur_l1->next;
            }
            if(out_size - i <= n){
                ans[i] += cur_l2->val;
                cur_l2 = cur_l2->next;
            }
        }
        // Normalize each digit
        int carry = 0;
        for(int i = out_size-1; i >= 0; i--){
            ans[i] += carry;
            carry = ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
        ListNode *out_l = nullptr;
        ListNode *cur = nullptr, *prev = nullptr;
        for(int i = 0; i < out_size; i++){
            // a leading zero
            if(i == 0 and ans[i] == 0) continue;
            if(out_l == nullptr){
                out_l = new ListNode(ans[i]);
                cur = out_l;
            }else cur = new ListNode(ans[i]);
            
            if(prev != nullptr) prev->next = cur;

            prev = cur;
        }
        return out_l;
    }
};
