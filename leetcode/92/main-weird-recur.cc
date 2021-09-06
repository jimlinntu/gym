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
    ListNode *l;
    // Recursion data swapping algorithm
    // use recursion to store r's previous pointer
    void solve(ListNode *r, int right, bool &end){
        if(right < 0) return;
        solve(r->next, right-1, end);
        if(l == r or r->next ==l){
            end = true;
            return; // same one, no need to swap
        }
        if(end) return;
        swap(l->val, r->val);
        l = l->next; // global movement
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        left--, right--;
        l = head;
        ListNode *r = head;
        for(; left > 0; l = l->next, r = r->next, left--, right--){
        }
        bool end = false;
        solve(r, right, end);
        return head;
    }
};
