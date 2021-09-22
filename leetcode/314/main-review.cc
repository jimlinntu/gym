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

struct E{
    TreeNode *node;
    int col;
};
class Solution {
public:
    unordered_map<int, vector<int>> map;

    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == nullptr) return {};
        int mm = 0, mx = 0;
        queue<E> q;
        // Node, col
        q.push({root, 0});
        vector<vector<int>> ans;
        while(!q.empty()){
            E e = q.front();
            q.pop();
            mm = min(mm, e.col);
            mx = max(mx, e.col);
            map[e.col].push_back(e.node->val);

            if(e.node->left) q.push({e.node->left, e.col-1});
            if(e.node->right) q.push({e.node->right, e.col+1});
        }
        for(int c = mm; c <= mx; c++){
            ans.push_back({});
            ans.back().insert(ans.back().begin(),
                              map[c].begin(), map[c].end());
        }
        return ans;
    }
};
