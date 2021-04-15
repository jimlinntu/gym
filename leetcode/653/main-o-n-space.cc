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
    void flatten(TreeNode *root, deque<int> &dq){
        if(root->left != nullptr) flatten(root->left, dq);
        dq.push_back(root->val);
        if(root->right != nullptr) flatten(root->right, dq);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        deque<int> dq;
        flatten(root, dq);
        // Solving two sums problem by two pointers
        // in O(n) time
        int n = dq.size();
        if(n == 1) return false;
        int start = 0, end = n-1;
        while(start < end){
            int sum = dq[start] + dq[end];
            if(sum == k) return true;
            if(sum < k){
                // the sum is too small, move start
                // We can safely discard dq[start]
                // because even if it adds the largest number it still is too small
                start++;
            }else{
                // the sum is too big, move end
                // We can safely discard dq[end]
                // because even if it adds the smallest number it still is too big!
                end--;
            }
            
        }
        return false;
    }
};
