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
    int ans_depth = 0;
    TreeNode *ans = nullptr;

    int dfs(TreeNode *cur, int depth){
        if(cur == nullptr){
            ans_depth = max(ans_depth, depth);
            return depth;
        }
        
        int l = dfs(cur->left, depth+1);
        int r = dfs(cur->right, depth+1);
        
        if(l == r and l == ans_depth){
            ans = cur;
        }
        return max(l, r); // report the maximum depth nodes under this subtree
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
