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
    vector<TreeNode*> build(int start, int end){
        if(start > end) return {nullptr};
        if(start == end){
            return {new TreeNode(start)};
        }
        vector<TreeNode*> trees;
        // Each number can be a possible root
        for(int i = start; i <= end; i++){
            vector<TreeNode*> left_trees = build(start, i-1);
            vector<TreeNode*> right_trees = build(i+1, end);
            int l_n = left_trees.size();
            int r_n = right_trees.size();
            // Loop over each combination
            for(int j = 0; j < l_n; j++){
                for(int k = 0; k < r_n; k++){
                    trees.push_back(
                        new TreeNode(i, left_trees[j], right_trees[k]));
                }
            }
        }
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};
