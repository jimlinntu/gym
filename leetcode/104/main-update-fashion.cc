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

void dfs(TreeNode *current, int depth, int &max_depth){
    if(current == nullptr){
        // update the max_depth
        max_depth = (depth < max_depth)? (max_depth):(depth);
        return;
    }
    dfs(current->left, depth+1, max_depth);
    dfs(current->right, depth+1, max_depth);
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        dfs(root, 0, max_depth);
        return max_depth;
    }
};
