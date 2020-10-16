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
        }
        return;
    }
    TreeNode* _deserialize(int upper_bound, int &idx, vector<string> &tokens){
        if(idx == tokens.size()) return nullptr;
        int val = stoi(tokens[idx]);
        // Test if we can put this value in the current node.
        // If not, we are pretty sure this node should be a nullptr
        if(val > upper_bound) return nullptr;
        idx++; // consume a token
        TreeNode *cur = new TreeNode(val);
        // left branch element < val
        cur->left = _deserialize(val, idx, tokens);
        cur->right = _deserialize(upper_bound, idx, tokens);
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
        vector<string> tokens;
        string token;
        while(datastream >> token){
            tokens.push_back(token);
        }
        int idx = 0;
        TreeNode *root = _deserialize(numeric_limits<int>::max(), idx, tokens);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
