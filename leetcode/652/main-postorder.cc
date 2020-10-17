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
    unordered_map<string, int> map;
    string postorder_serialize(TreeNode *cur, vector<TreeNode*> &duplicates){
        if(cur == nullptr){
            return "n ";
        }
        string left_serial = postorder_serialize(cur->left, duplicates);
        string right_serial = postorder_serialize(cur->right, duplicates);
        string serial = left_serial + right_serial + to_string(cur->val) + " ";
        
        auto it = map.find(serial);
        if(it != map.end()){
            // if this is the second time this serial number appears,
            if(++(it->second) == 2){
                duplicates.push_back(cur);
            }
        }else{
            map.insert({serial, 1}); // the first time this serial appears
        }
        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map.clear();
        vector<TreeNode*> duplicates;
        postorder_serialize(root, duplicates);
        return duplicates;
    }
};
