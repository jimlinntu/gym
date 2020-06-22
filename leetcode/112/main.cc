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

using LL = long long int;

void solve(TreeNode *current, int sum, LL &s, bool &has){
    // if found
    if(has) return;

    s += (LL)current->val;
    // a leaf node
    if(current->left == nullptr and current->right == nullptr){
        if(s == sum) has = true;
    }

    if(current->left != nullptr){
        solve(current->left, sum, s, has);
    }
    if(current->right != nullptr){
        solve(current->right, sum, s, has);
    }

    s -= (LL)current->val;
    return;
}
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        bool has = false;
        LL s = 0;
        solve(root, sum, s, has);
        return has;
    }
};
