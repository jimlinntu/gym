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
    int min, max;
};
class Solution {
public:
    bool isvalid = true;
    R solve(TreeNode *root){
        if(!isvalid) return {-1, -1};
        int mn = root->val, mx = root->val;
        if(root->left){
            R left = solve(root->left);
            if(left.max >= root->val){
                isvalid = false;
                return {-1, -1};
            }
            mn = left.min;
        }
        if(root->right){
            R right = solve(root->right);
            if(right.min <= root->val){
                isvalid = false;
                return {-1, -1};
            }
            mx = right.max;
        }
        return {mn, mx};
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        solve(root);
        return isvalid;
    }
};
