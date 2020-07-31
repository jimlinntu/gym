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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        // BFS
        int max_width = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            max_width = max(max_width, q.back().second - q.front().second + 1);
            int offset = q.front().second;
            for(int i = q.size(); i > 0; i--){
                TreeNode *cur = q.front().first;
                int idx = q.front().second - offset;
                q.pop();
                if(cur->left) q.push({cur->left, 2*idx+1});
                if(cur->right) q.push({cur->right, 2*idx+2});
            }
        }
        return max_width;
    }
};
