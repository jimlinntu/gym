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
    //
    void get_deepest(TreeNode *cur, int depth){
        if(cur == nullptr){
            ans_depth = max(ans_depth, depth);
            return;
        }
        get_deepest(cur->left, depth+1);
        get_deepest(cur->right, depth+1);
        return;
    }

    int solve(TreeNode *cur, int depth){
        if(cur == nullptr){
            if(depth == ans_depth) ans = cur;
            return depth;
        }
        
        int l = solve(cur->left, depth+1);
        int r = solve(cur->right, depth+1);
        // If both subtrees contain the deepest nodes,
        // we set this
        if(l == ans_depth and r == ans_depth){
            ans = cur;
        }
        return max(l, r);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        get_deepest(root, 0);
        solve(root, 0);
        return ans;
    }
};
