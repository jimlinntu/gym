/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // "<left tree><right tree>;root->val:left,right"
    int _serialize(TreeNode *root, string &s){
        if(root == nullptr) return 0;
        int n = s.size();
        int left = _serialize(root->left, s);
        int right = _serialize(root->right, s);
        s += ";" + to_string(root->val) + ":" + \
             to_string(left) + "," + to_string(right);
        return s.size() - n;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        _serialize(root, s);
        return s;
    }

    TreeNode* _deserialize(string &s, int start, int end){
        if(start >= end) return nullptr;
        int anchor = start;
        for(int i = end-1; i >= start; i--){
            if(s[i] == ';'){
                anchor = i;
                break;
            }
        }
        // Parse: "......;root->val:left,right"
        int idx = s.find(':', anchor);
        int val = stoi(s.substr(anchor+1, idx-anchor-1));

        int idx2 = s.find(',', idx);
        int left = stoi(s.substr(idx+1, idx2-idx-1));
        int right = stoi(s.substr(idx2+1));

        TreeNode *root = new TreeNode(val);
        root->left = _deserialize(s, start, start+left);
        root->right = _deserialize(s, start+left, start+left+right);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return _deserialize(data, 0, data.size());
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
