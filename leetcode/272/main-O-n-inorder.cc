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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if(k == 0) return {};
        queue<int> ans;
        stack<TreeNode*> s;
        // Inorder traversal
        TreeNode *cur = root;
        while(cur or !s.empty()){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if(ans.size() < k) ans.push(cur->val);
            else if(ans.size() == k and
                    abs(target - cur->val) < abs(target - ans.front())){
                // pop the largest difference one
                ans.pop();
                ans.push(cur->val);
            }
            cur = cur->right;
        }
        vector<int> ans_v;
        while(!ans.empty()){
            ans_v.push_back(ans.front());
            ans.pop();
        }
        return ans_v;
    }
};
