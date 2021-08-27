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
    ListNode *cur;
    // Proof: mathematical induction
    // when n == 1: this algorithm works
    // assume n <= k: this algorithm will works
    // when n = k+1:
    // when we divide n into two parts
    // because n/2 <= k, left side can correctly walk through the list
    // so cur will be the middle node
    // and n/2 <= k on the right will also be walked through correctly
    TreeNode *build(int start, int end){
        if(start >= end) return nullptr;
        int mid = (start + end) / 2;
        // walk half of the inorder list
        TreeNode *left = build(start, mid);
        // Inorder visit
        TreeNode *root = new TreeNode(cur->val);
        cur = cur->next;
        // 
        TreeNode *right = build(mid+1, end);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        for(auto c = head; c != nullptr; c = c->next){
            n++;
        }
        cur = head;
        return build(0, n);
    }
};
