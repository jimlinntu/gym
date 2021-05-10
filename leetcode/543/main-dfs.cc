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
    int max_path = 0;
    // Intuition:
    // Because the longest path must have to "turn" at node,
    // we can just try every subtree's root as it "turning" point.
    int dfs(TreeNode *cur){
        if(cur == nullptr) return 0;
        int left_depth = dfs(cur->left);
        int right_depth = dfs(cur->right);
        max_path = max(max_path, left_depth + right_depth + 1);
        return max(left_depth, right_depth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max_path-1;
    }
};
