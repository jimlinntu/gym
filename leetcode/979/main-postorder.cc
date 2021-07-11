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
    // Idea:
    // Observe that on leaf nodes:
    // if node.val > 1, it must push node.val-1 coins up to its parent
    // else if node.val == 1, do nothing
    // else: it must steal coins from its parent
    // After leaf nodes are all traversed, we can virtually remove all leaf nodes
    // and deal with the new leaf nodes deterministically
    // This prompt us to use postorder traversal to solve this problem
    int ans = 0;
    int solve(TreeNode *root){
        if(root == nullptr) return 0;
        int remain = solve(root->left) + solve(root->right);
        root->val += remain;
        
        if(root->val == 1) return 0;
        else if(root->val > 1){
            // move these coins up
            ans += root->val-1;
            return root->val-1;
        }else{
            // in need of coins, steal it from its parent
            ans += 1-root->val;
            return -(1-root->val);
        }
    }
    int distributeCoins(TreeNode* root) {
        assert(solve(root) == 0);
        return ans;
    }
};
