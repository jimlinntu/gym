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
    
    void _serialize(TreeNode *cur, string &data){
        if(cur != nullptr){
            data += to_string(cur->val) + " ";
            _serialize(cur->left, data);
            _serialize(cur->right, data);
        }else{
            data += "n "; // null
        }
        return;
    }
    TreeNode* _deserialize(istringstream &datastream){
        string token;
        datastream >> token;
        if(token == "n") return nullptr;
        TreeNode *cur = new TreeNode(stoi(token));
        cur->left = _deserialize(datastream);
        cur->right = _deserialize(datastream);
        return cur;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        _serialize(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream datastream(data);
        TreeNode *root = _deserialize(datastream);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

