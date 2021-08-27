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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode *find_mid(ListNode *s, ListNode *e){
        ListNode *slow = s;
        ListNode *fast = s->next;
        while(fast != e){
            slow = slow->next;
            if(fast->next != e) fast = fast->next->next;
            else fast = fast->next;
        }
        // Even: 1 -> 2 -> 3 -> 4
        // Odd: 1 -> 2 -> 3
        return slow; // middle
    }
    // T(n) = T(n/2) + O(n) ==> T(n) = O(n log n)
    TreeNode *build(ListNode *start, ListNode *end){
        if(start == end) return nullptr;
        ListNode *mid = find_mid(start, end);
        TreeNode *cur = new TreeNode(mid->val);
        cur->left = build(start, mid);
        cur->right = build(mid->next, end);
        return cur;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, nullptr);
    }
};
