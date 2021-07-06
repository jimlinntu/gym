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

struct H{
    size_t operator()(const pair<TreeNode*, bool> &e) const{
        size_t h1 = hash<TreeNode*>()(e.first);
        size_t h2 = hash<bool>()(e.second);
        return h1 ^ h2;
    }
};

class Solution {
public:
    unordered_map<pair<TreeNode*, bool>, int, H> map;
    int solve(TreeNode *root, bool iscover){
        if(root == nullptr) return 0;
        // If this node is already covered
        // we compute the sum of left and right
        if(map.find({root, iscover}) != map.end()) return map[{root, iscover}];

        if(iscover){
            // 1. put at this node
            // 2. not put at this node
            return min(1+solve(root->left, true)+solve(root->right, true),
                       solve(root->left, false)+solve(root->right, false));
        }

        // 1. To put at this node
        int min_num = 1 + solve(root->left, true) + solve(root->right, true);
        // 2. Not to put at this node (must have at least one child)
        // 2.1 put at the left child
        if(root->left)
            min_num = min(min_num,
                          1+solve(root->left->left, true)+solve(root->left->right, true)
                          +solve(root->right, false));
        if(root->right)
            min_num = min(min_num,
                          1+solve(root->right->left, true)+solve(root->right->right, true)
                          + solve(root->left, false));
        return min_num;
    }
    int minCameraCover(TreeNode* root) {
        return solve(root, false);
    }
};
