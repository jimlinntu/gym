class Solution {
public:
    string decodeString(string s) {
        stack<int> cntstk;
        vector<string> strstk;
        string cur;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                int idx = s.find('[', i);
                int k = stoi(s.substr(i, idx-i));
                cntstk.push(k);
                strstk.push_back(cur);
                cur = ""; //reset
                i = idx;
            }else if(s[i] == ']'){
                // Expand
                int k = cntstk.top();
                cntstk.pop();
                // repeat k-1 times
                string tmp = cur;
                for(int j = 0; j < k-1; j++){
                    cur += tmp;
                }
                // restore our workspace
                cur = strstk.back() + cur;
                strstk.pop_back();
            }else{
                // append to our current workspace
                cur.push_back(s[i]);
            }
        }
        return cur;
    }
};
