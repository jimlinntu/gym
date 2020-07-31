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
    int max_width;
    void dfs(TreeNode *cur, int cur_idx, int depth, vector<int> &leftmost){
        // Intuition: dfs will traverse the leftmost branch first.
        // Therfore, it is very suitable for our scenario

        // if this is the first time we encounter this depth
        if(leftmost.size() == depth){
            leftmost.push_back(cur_idx);
        }

        max_width = max(max_width, cur_idx - leftmost[depth] + 1);
        // shift the current index to avoid overflow
        cur_idx = cur_idx - leftmost[depth];

        if(cur->left != nullptr){
            dfs(cur->left, cur_idx*2+1, depth+1, leftmost);
        }

        if(cur->right != nullptr){
            dfs(cur->right, cur_idx*2+2, depth+1, leftmost);
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        max_width = 0;
        vector<int> leftmost;
        dfs(root, 0, 0, leftmost);
        return max_width;
    }
};
