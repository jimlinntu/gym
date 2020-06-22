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

using Path = vector<int>;

void solve(TreeNode *current, int sum, int &s, Path &p, vector<Path> &ans){
    s += current->val;
    p.push_back(current->val);

    if(current->left == nullptr and current->right == nullptr){
        if(s == sum) ans.push_back(p);
    }
    
    if(current->left != nullptr) solve(current->left, sum, s, p, ans);
    if(current->right != nullptr) solve(current->right, sum, s, p, ans);

    s -= current->val;
    p.pop_back();
}

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<Path> ans;
        if(root == nullptr) return ans;
        else{
            int s = 0;
            Path p;
            solve(root, sum, s, p, ans);
            return ans;
        }
    }
};
