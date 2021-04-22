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
struct RobRet{
    int to_rob;
    int not_to_rob;
    RobRet(){
        to_rob = not_to_rob = 0;
    }
};
class Solution {
public:
    RobRet solve(TreeNode *root){
        RobRet l, r, ret;
        if(root->left != nullptr) l = solve(root->left);
        if(root->right != nullptr) r = solve(root->right);
        // This node is robbed
        ret.to_rob = root->val + l.not_to_rob + r.not_to_rob;
        // This node is not robbed
        ret.not_to_rob = max(l.to_rob, l.not_to_rob)+
                           max(r.to_rob, r.not_to_rob);
        return ret;
    }
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        RobRet r = solve(root);
        return max(r.to_rob, r.not_to_rob);
    }
};
