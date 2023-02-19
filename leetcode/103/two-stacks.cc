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
    // 3 (-->) level = 0
    // 9 20 (<--) level = 1
    // 1 2 3 4 (-->) level = 2
    // ........(<--) level = 3

    // stk1 = {3}, stk2 = {}
    // stk1 = {},  stk2 = {9, 20}
    // stk1 = {4, 3, 2, 1}, stk2 = {}
    // In practice, we swap(stk1, stk2) at the end of the loop
    // but conceptually they are different queues
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int>> ans;
        stack<TreeNode*> s1, s2;
        stack<TreeNode*> *p1 = &s1, *p2 = &s2;
        // Put the first node into the stack
        if(root) p1->push(root);
        while(!p1->empty()){
            // Initialize this level's vector<int>
            ans.push_back(vector<int>());
            // Set a reference `back` so that it is easy to add values later
            vector<int> &back = ans.back();
            while(!p1->empty()){
                // Pop the current stack
                TreeNode *cur = p1->top();
                back.push_back(cur->val);
                p1->pop();
                // Push to the second stack
                if(level % 2 == 1){
                    if(cur->right) p2->push(cur->right);
                    if(cur->left) p2->push(cur->left);
                }else{
                    if(cur->left) p2->push(cur->left);
                    if(cur->right) p2->push(cur->right);
                }
            }
            // swap p1 p2
            swap(p1, p2);
            level++;
        }
        return ans;
    }
};
