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
    vector<vector<int>> ans;
    vector<int> path;
    
    bool isleaf(TreeNode *cur){
        if(cur == nullptr) return false;
        return cur->left == nullptr and cur->right == nullptr;
    }

    void solve(TreeNode *cur, int s, int t){
        if(cur == nullptr) return;
        // Enter this node
        s += cur->val;
        path.push_back(cur->val);

        if(isleaf(cur) and s == t){
            ans.push_back(path);
        }

        solve(cur->left, s, t);
        solve(cur->right, s, t);

        // Leave this node
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, 0, targetSum);
        return ans;
    }
};
