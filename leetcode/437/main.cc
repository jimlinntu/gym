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

using LL = long long int;

void solve(TreeNode *cur, LL pathsum, int sum, unordered_map<LL, int> &presum_count, int &ans){

    pathsum += cur->val;
    // Find if there is a previous node satisfy:
    // pathsum - ? = sum <-> pathsum - sum = ?
    auto it = presum_count.find(pathsum-sum);
    if(it != presum_count.end()){
        ans += it->second; // actually, this might be zero
    }

    // save this pathsum
    presum_count[pathsum]++;

    if(cur->left != nullptr){
        solve(cur->left, pathsum, sum, presum_count, ans);
    }
    if(cur->right != nullptr){
        solve(cur->right, pathsum, sum, presum_count, ans);
    }
    // Leave this node, delete this pathsum by 1
    presum_count[pathsum]--;
    return;
}
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        unordered_map<LL, int> presum_count;
        LL pathsum = 0;
        int ans = 0;
        presum_count[0] = 1; // from root to some child node
        solve(root, pathsum, sum, presum_count, ans);
        return ans;
    }
};
