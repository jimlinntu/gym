/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
enum State{
    not_visit, visit_left, visit_both
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, State>> stk;
        if(root) stk.push({root, not_visit});
        TreeNode *cur;
        State state;
        bool found_one = false;
        TreeNode *ans = nullptr;
        // Intuition: the standard stack dfs will pop out the node that is already visited
        // but here we maintain an additional state to let the path be traced
        while(!stk.empty()){
            tie(cur, state) = stk.top();
            if(state == not_visit and (cur == p or cur == q)){
                if(!found_one){
                    found_one = true;
                    ans = cur;
                }else{
                    break;
                }
            }
            if(state == not_visit){
                stk.top().second = visit_left; // transition
                if(cur->left) stk.push({cur->left, not_visit});
            }else if(state == visit_left){
                stk.top().second = visit_both; // transition
                if(cur->right) stk.push({cur->right, not_visit});
            }else{
                stk.pop();
                // backtracking
                if(found_one and cur == ans){
                    assert(!stk.empty());
                    ans = stk.top().first;
                    cout << ans->val << endl;
                }
            }
        }
        return ans;
    }
};
