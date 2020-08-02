
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
    void search(TreeNode *cur, int depth, vector<vector<int>> &level_nodes){
        if(level_nodes.size() == depth){
            level_nodes.push_back(vector<int>());
        }

        if(cur->left){
            search(cur->left, depth+1, level_nodes);
        }

        if(cur->right){
            search(cur->right, depth+1, level_nodes);
        }

        level_nodes[depth].push_back(cur->val);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> level_nodes;
        if(root == nullptr) return level_nodes;
        search(root, 0, level_nodes);
        vector<vector<int>> rev_level_nodes(level_nodes.rbegin(), level_nodes.rend());
        return rev_level_nodes;
    }
};
