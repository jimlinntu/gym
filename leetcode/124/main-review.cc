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
    int ans = INT_MIN;
    // Intuition:
    // categorize all paths by passing through different subtree root nodes
    int dfs(TreeNode *root){
        if(root == nullptr) return INT_MIN;
        // left, right are the maximum path sum starting from root->left/right
        // Note: this maximum path sum will go straight down
        int left = dfs(root->left);
        int right = dfs(root->right);
        // 4 options (key is the path we are considering here will pass this root):
        // 1. root itself, ignore its childrens maximum path sum
        // 2. root->val + left
        // 3. root->val + right
        // 4. root->val + left + right (this cannot be returned)
        int ret = root->val;
        if(left != INT_MIN) ret = max(ret, root->val + left);
        if(right != INT_MIN) ret = max(ret, root->val + right);

        if(left != INT_MIN and right != INT_MIN)
            ans = max(ans, root->val + left + right);
        ans = max(ans, ret);
        return ret;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
