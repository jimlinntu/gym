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
    unordered_map<int, map<int, vector<int>>> map;
    int mm = INT_MAX, mx = INT_MIN;
    void traverse(TreeNode *cur, int row, int col){
        if(cur == nullptr) return;
        mm = min(mm, col);
        mx = max(mx, col);

        map[col][row].push_back(cur->val);

        traverse(cur->left, row+1, col-1);
        traverse(cur->right, row+1, col+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        // Flatten
        vector<vector<int>> ans;
        for(int i = mm; i <= mx; i++){
            auto &mp = map[i];
            ans.push_back({});
            for(auto it = mp.begin(); it != mp.end(); it++){
                auto &v = it->second;
                sort(v.begin(), v.end());
                ans.back().insert(ans.back().end(), v.begin(), v.end());
            }
        }
        return ans;
    }
};
