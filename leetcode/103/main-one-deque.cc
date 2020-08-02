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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if(root == nullptr) return levels;
        int l = 0;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while(!dq.empty()){
            levels.push_back(vector<int>());
            for(int i = dq.size(); i > 0; i--){
                TreeNode *cur;
                if(l%2){
                    cur = dq.back();
                    dq.pop_back();
                    if(cur->right) dq.push_front(cur->right);
                    if(cur->left) dq.push_front(cur->left);
                }else{
                    cur = dq.front();
                    dq.pop_front();
                    if(cur->left) dq.push_back(cur->left);
                    if(cur->right) dq.push_back(cur->right);
                }

                levels[l].push_back(cur->val);
            }
            l++; 
        }
        return levels;
    }
};
