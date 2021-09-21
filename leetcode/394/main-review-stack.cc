class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string stk;
        for(int i = 0; i < n; i++){
            if(s[i] == ']'){
                // pop out
                string dup;
                while(stk.back() != '['){
                    dup.push_back(stk.back());
                    stk.pop_back();
                }
                stk.pop_back(); // '['
                reverse(dup.begin(), dup.end());
                // pop until we don't find any digit
                string num_str;
                while(!stk.empty() and isdigit(stk.back())){
                    num_str.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(num_str.begin(), num_str.end());
                int k = stoi(num_str);
                
                for(int j = 0; j < k; j++){
                    stk += dup;
                }
            }else stk.push_back(s[i]);
        }
        return stk;
    }
};
