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
    TreeNode *ans = nullptr;
    // solve(root) == (has_p, has_q)
    pair<bool, bool> solve(TreeNode *root,
                           TreeNode *p,
                           TreeNode *q){
        if(root == nullptr) return {false, false};
        bool has_p = false, has_q = false;
        if(root == p) has_p = true;
        else if(root == q) has_q = true;

        auto ret = solve(root->left, p, q);
        has_p |= ret.first;
        has_q |= ret.second;
        
        // if the left subtree contains p and q, do not proceed to the right tree
        if(!(has_p and has_q)){
            ret = solve(root->right, p, q);
            has_p |= ret.first;
            has_q |= ret.second;
        }

        if(ans == nullptr and has_p and has_q) ans = root;
        return {has_p, has_q};
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        return ans;
    }
};
