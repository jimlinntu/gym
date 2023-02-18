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
    
    int minDiffInBST(TreeNode* root) {
        TreeNode *cur = root;
        TreeNode *prev = nullptr;
        stack<TreeNode*> s;
        int ans = numeric_limits<int>::max();
        while(cur != nullptr or !s.empty()){
            while(cur != nullptr){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if(prev != nullptr){
                ans = min(ans, cur->val - prev->val);
            }
            // store the previous result
            prev = cur;
            // move on to the next node
            cur = cur->right;
        }
        return ans;
    }
};
