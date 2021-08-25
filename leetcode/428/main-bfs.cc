/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s;
        queue<Node*> q;
        if(root){
            q.push(root);
            // $ indicates the end of children
            // # indicates the end of this level
            s += to_string(root->val) + ",$";
        }else{
            s += "N,$";
        }
        while(!q.empty()){
            for(int i = q.size()-1; i >= 0; i--){
                Node *cur = q.front();
                q.pop();
                for(Node *c: cur->children){
                    if(c){
                        s += to_string(c->val) + ",";
                        q.push(c);
                    }else s += "N,";
                }
                s += "$";
            }
        }
        return s;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data[0] == 'N') return nullptr;
        int cur = data.find(",");
        Node *root = new Node(stoi(data.substr(0, cur)));
        // "N,$"
        cur += 2;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node *parent = q.front();
            q.pop();
            // Until we encounter the end of 
            for(int next; data[cur] != '$'; cur = next+1){
                next = data.find(',', cur); 
                if(data.substr(cur, next-cur) == "N"){
                    parent->children.push_back(nullptr);
                }else{
                    int val = stoi(data.substr(cur, next-cur));
                    parent->children.push_back(new Node(val));
                    q.push(parent->children.back());
                }
            }
            assert(data[cur] == '$');
            cur++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
