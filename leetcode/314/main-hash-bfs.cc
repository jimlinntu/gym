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
    int min_col = INT_MAX;
    int max_col = INT_MIN;
    // map[col_num] == the numbers on this column
    unordered_map<int, vector<int>> map;

    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if(root != nullptr) q.push({root, 0});
        while(!q.empty()){
            TreeNode *node;
            int col;
            tie(node, col) = q.front();
            q.pop();
            map[col].push_back(node->val);
            min_col = min(min_col, col);
            max_col = max(max_col, col);

            if(node->left) q.push({node->left, col-1});
            if(node->right) q.push({node->right, col+1});
        }
        vector<vector<int>> ans;
        for(int i = min_col; i <= max_col; i++)
            ans.push_back(map[i]);
        return ans;
    }
};
