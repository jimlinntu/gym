class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        // FFFF....F
        ans.push_back(s);
        for(int i = 0; i < n; i++){
            int ans_n = ans.size();
            if(isdigit(s[i])) continue;
            for(int j = 0; j < ans_n; j++){
                // make this c upper
                ans.push_back(ans[j]);
                if(islower(s[i])) ans.back()[i] = toupper(ans.back()[i]);
                else ans.back()[i] = tolower(ans.back()[i]);
            }
        }
        return ans;
    }
};
