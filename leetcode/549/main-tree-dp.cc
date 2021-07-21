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

struct R{
    int len_inc, len_dec; // increasing, decreasing
};
class Solution {
public:
    // Each path must pass a subtree's root
    // So it is intuitive to solve it for each subtree's root
    // return the longest consecutive from parent to a child
    // but when computing the max_len, we should consider: left + root + right path
    int max_len = 0;
    R solve(TreeNode *root){
        if(root == nullptr) return {0, 0};

        R l = solve(root->left);
        R r = solve(root->right);
        
        R cur = {1, 1}; // itself can form length 1 increasing and decreasing seq
        if(root->left){
            // increasing
            if(root->val+1 == root->left->val)
                cur.len_inc = max(cur.len_inc, l.len_inc+1);
            // decreasing
            if(root->val-1 == root->left->val)
                cur.len_dec = max(cur.len_dec, l.len_dec+1);
        }
        if(root->right){
            // increasing
            if(root->val+1 == root->right->val)
                cur.len_inc = max(cur.len_inc, r.len_inc+1);
            // decreasing
            if(root->val-1 == root->right->val)
                cur.len_dec = max(cur.len_dec, r.len_dec+1);
        }
        // left -- root or root -- right
        max_len = max({max_len, cur.len_inc, cur.len_dec});
        
        // left -- root -- right
        // Ex. 1 2 3 or 3 2 1

        if(root->left and root->right){
            // left decreasing, right increasing
            if(root->left->val == root->val-1 and root->val+1 == root->right->val){
                max_len = max(max_len, l.len_dec + 1 + r.len_inc);
            }
            // left increasing, right decreasing
            if(root->left->val == root->val+1 and root->val-1 == root->right->val){
                max_len = max(max_len, l.len_inc + 1 + r.len_dec);
            }
        }
        return cur;
    }

    int longestConsecutive(TreeNode* root) {
        solve(root);
        return max_len;
    }
};
