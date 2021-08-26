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
    TreeNode *prev = nullptr;
    void solve(TreeNode *root){
        if(root == nullptr) return;
        if(!isvalid) return; // early break
        // Compare to the previous one
        solve(root->left);
        if(prev and prev->val >= root->val){
            isvalid = false;
            return;
        }
        prev = root; // visit this node
        solve(root->right);
    }
    bool isValidBST(TreeNode* root) {
        solve(root);
        return isvalid;
    }
};
