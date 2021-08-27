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
    TreeNode *build(vector<ListNode*> &v, int start, int end){
        // choose the middle one as the root
        if(start >= end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(v[mid]->val);
        root->left = build(v, start, mid);
        root->right = build(v, mid+1, end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*> v;
        for(auto cur = head; cur != nullptr; cur = cur->next){
            v.push_back(cur);
        }
        return build(v, 0, v.size());
    }
};
