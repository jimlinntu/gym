/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // O(log n) time and space
    TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root == nullptr){
            assert(false); // This should not happen
            return nullptr;
        }
        if(root->val == p->val) return root;
        if(root->val == q->val) return root;

        if(p->val < root->val and q->val < root->val){
            // Both are on the left
            return solve(root->left, p, q);
        }else if(p->val > root->val and q->val > root->val){
            // Both are on the right
            return solve(root->right, p, q);
        }else{
            // They are on different subtrees
            return root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};
