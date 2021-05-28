class Codec {
public:
    string delimiter = "|";
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // str -> num#str
        // Ex. ["|123awerwer", "1234567"]
        // ---> 10|123awerwer7|1234567
        string encoded;
        for(string &s: strs){
            encoded += to_string(s.size()) + delimiter + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int n = s.length();
        for(int idx = 0; idx < n;){
            // The index of a delimiter
            int didx = s.find(delimiter, idx);
            int len = stoi(s.substr(idx, didx-idx));
            decoded.push_back(s.substr(didx+1, len));
            // next
            idx = didx+1+len;
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
