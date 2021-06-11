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
    int closestValue(TreeNode* root, double target) {
        assert(root != nullptr);
        TreeNode *cur = root;
        int ans = cur->val;
        while(cur != nullptr){
            if(target == (double)cur->val) return cur->val;
            // if this difference is smaller, replace it with the new number
            if(abs(target - cur->val) < abs(target - ans)){
                ans = cur->val;
            }
            // go left, because going right will only cause the difference become larger!
            if(target < cur->val) cur = cur->left;
            // go right
            else cur = cur->right;
        }
        return ans;
    }
};
