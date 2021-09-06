/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        stack<TreeNode*> stk;
        // Find p
        if(root) stk.push(root);
        while(!stk.empty()){
            TreeNode *cur = stk.top();
            if(cur == p) break;
            stk.pop();
            if(cur->left){
                parent[cur->left] = cur;
                stk.push(cur->left);
            }
            if(cur->right){
                parent[cur->right] = cur;
                stk.push(cur->right);
            }
        }
        // Find q
        stk = {};
        if(root) stk.push(root);
        while(!stk.empty()){
            TreeNode *cur = stk.top();
            if(cur == q) break;
            stk.pop();
            if(cur->left){
                parent[cur->left] = cur;
                stk.push(cur->left);
            }
            if(cur->right){
                parent[cur->right] = cur;
                stk.push(cur->right);
            }
        }
        // root -----> p
        unordered_set<TreeNode*> ppath;
        ppath.insert(p);
        TreeNode *cur = p;
        while(parent.count(cur)){
            cur = parent[cur];
            ppath.insert(cur);
        }
        cur = q;
        if(ppath.count(q)) return q;
        while(parent.count(cur)){
            cur = parent[cur];
            if(ppath.count(cur)) return cur;
        }
        return nullptr;
    }
};
